module.exports = () => ({
  // The list of plugins for PostCSS
  // https://github.com/postcss/postcss
  syntax: 'postcss-scss',
  plugins: [
    require('postcss-preset-env')({ stage: 0 }),
    require('autoprefixer')({
      browsers: ['>5%', 'last 2 versions']
    })
  ]
});
