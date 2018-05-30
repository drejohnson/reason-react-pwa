open Utils;

[@bs.module "./registerServiceWorker"]
external registerServiceWorker : unit => unit = "default";

requireCSS("@material/button/dist/mdc.button.min.css");

/* requireCSS("@material/toolbar/dist/mdc.toolbar.min.css"); */
requireCSS("@material/layout-grid/dist/mdc.layout-grid.min.css");

requireCSS("@material/typography/dist/mdc.typography.min.css");

requireCSS("@material/drawer/dist/mdc.drawer.min.css");

requireCSS("@material/list/dist/mdc.list.min.css");

requireCSS("@material/top-app-bar/dist/mdc.top-app-bar.min.css");

requireCSS("@material/card/dist/mdc.card.min.css");

requireCSS("@material/icon-toggle/dist/mdc.icon-toggle.min.css");

requireCSS("@material/fab/dist/mdc.fab.min.css");

requireCSS("./Index.css");

ReactDOMRe.renderToElementWithId(<App name="ReasonML" />, "root");

registerServiceWorker();

[@bs.val] external hot : bool = "module.hot";

[@bs.val] external accept : unit => unit = "module.hot.accept";

if (hot) {
  accept();
};