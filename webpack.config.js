const path = require('path');
const history = require('connect-history-api-fallback');
const convert = require('koa-connect');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const ScriptExtHtmlPlugin = require('script-ext-html-webpack-plugin');
const UglifyJsPlugin = require('uglifyjs-webpack-plugin');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');
const OptimizeCSSAssetsPlugin = require('optimize-css-assets-webpack-plugin');
const WorkboxPlugin = require('workbox-webpack-plugin');
const { BundleAnalyzerPlugin } = require('webpack-bundle-analyzer');
const WebpackBar = require('webpackbar');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: {
    app: './src/Index.bs.js'
  },
  mode: isProd ? 'production' : 'development',
  output: {
    path: path.resolve(__dirname, './dist'),
    filename: !isProd ? '[name].js' : '[name].[chunkhash:8].js',
    publicPath: '/'
  },
  resolve: {
    extensions: ['.bs.js', '.js', '.scss', '.sass', '.css', '.html'],
    alias: {
      '~': './src'
    },
    modules: ['./src', 'node_modules']
  },
  module: {
    rules: [
      {
        test: /\.s?[ac]ss$/,
        use: [
          !isProd ? 'style-loader' : MiniCssExtractPlugin.loader,
          'css-loader',
          'postcss-loader'
        ]
      },
      {
        test: /\.(jpe?g|png|gif|svg)$/,
        use: [
          {
            loader: 'url-loader',
            options: {
              limit: 8192, // return DataURL if image size <= 8KB
              name: 'assets/[name].[ext]',
              fallback: 'file-loader' // use file loader for size > 8KB
            }
          }
        ]
      },
      {
        test: /\.(woff|woff2|eot|ttf|otf)$/,
        use: ['file-loader']
      }
    ]
  },
  plugins: [
    new MiniCssExtractPlugin({
      // Options similar to the same options in webpackOptions.output
      // both options are optional
      filename: !isProd ? '[name].css' : '[name].[hash].css',
      chunkFilename: !isProd ? '[id].css' : '[id].[hash].css'
    }),
    new HtmlWebpackPlugin({
      minify: {
        collapseWhitespace: isProd,
        removeComments: isProd,
        removeRedundantAttributes: isProd,
        removeScriptTypeAttributes: isProd,
        removeStyleLinkTypeAttributes: isProd,
        sortAttributes: isProd,
        sortClassName: isProd,
        useShortDoctype: isProd,
        minifyCSS: isProd,
        minifyJS: isProd,
        caseSensitive: isProd
      },
      hash: isProd,
      inject: true,
      template: './public/index.html'
    }),
    new ScriptExtHtmlPlugin({
      defaultAttribute: 'defer',
      module: 'app'
    }),
    new WebpackBar(),
    ...(isProd
      ? [
          new WorkboxPlugin.GenerateSW({
            swDest: 'sw.js',
            clientsClaim: true,
            skipWaiting: true,
            // Exclude images from the precache
            exclude: [/\.(?:png|jpg|jpeg|svg)$/],
            // Define runtime caching rules.
            runtimeCaching: [
              {
                urlPattern: /^(https?.*)/,
                handler: 'networkFirst',
                options: {
                  cacheName: 'cache-https',
                  expiration: {
                    maxEntries: 50
                  },
                  networkTimeoutSeconds: 3
                }
              },
              {
                urlPattern: new RegExp('https://fonts.googleapis.com/(.*)'),
                // Apply a cache-first strategy.
                handler: 'cacheFirst',
                options: {
                  cacheName: 'googleapis',
                  expiration: {
                    maxEntries: 50
                  }
                }
              },
              {
                // Match any request ends with .png, .jpg, .jpeg or .svg.
                urlPattern: /\.(?:png|jpg|jpeg|svg)$/,

                // Apply a cache-first strategy.
                handler: 'cacheFirst',

                options: {
                  cacheName: 'images-cache',
                  // Only cache 10 images.
                  expiration: {
                    maxEntries: 60,
                    maxAgeSeconds: 30 * 24 * 60 * 60 // 30 Days
                  },
                  cacheableResponse: {
                    statuses: [0, 200]
                  }
                }
              },
              {
                urlPattern: /\.(?:js|css)$/,
                handler: 'staleWhileRevalidate',
                options: {
                  cacheName: 'static-resources'
                }
              },
              {
                urlPattern: /.*(?:googleapis)\.com.*$/,
                handler: 'staleWhileRevalidate',
                options: {
                  cacheName: 'googleapis-cache'
                }
              },
              {
                urlPattern: /.*(?:gstatic)\.com.*$/,
                handler: 'staleWhileRevalidate',
                options: {
                  cacheName: 'gstatic-cache'
                }
              }
            ]
          })
          // new BundleAnalyzerPlugin({ openAnalyzer: false })
        ]
      : [])
  ],
  optimization: {
    minimizer: [
      new UglifyJsPlugin({
        cache: true,
        // parallel: true,
        sourceMap: true // set to true if you want JS source maps
      }),
      new OptimizeCSSAssetsPlugin({})
    ],
    splitChunks: {
      cacheGroups: {
        commons: {
          test: /node_modules/,
          chunks: 'initial',
          name: 'vendor',
          priority: 10,
          enforce: true
        }
      }
    }
  }
};

if (!isProd) {
  module.exports.serve = {
    content: [__dirname],
    hot: true,
    add: (app, middleware, options) => {
      const historyOptions = {
        // ... see: https://github.com/bripkens/connect-history-api-fallback#options
      };

      app.use(convert(history(historyOptions)));
    }
  };
}
