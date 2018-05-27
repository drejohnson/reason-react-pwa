const critical = require('critical');
const config = require('./config');

critical.generate({
  inline: true,
  base: config.resolveApp('dist'),
  src: 'index.html',
  dest: 'index.html',
  width: 1300,
  height: 900
});
