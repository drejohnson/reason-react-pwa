type tag = [ | `String(string) | `ReactClass(ReasonReact.reactClass)];

let optionMap = (option, fn) => Belt.Option.map(option, fn);

/* Button */
module Button = {
  [@bs.module "rmwc/Button"]
  external reactClass : ReasonReact.reactClass = "Button";
  let make =
      (
        ~dir: option(string)=?,
        ~tag: option(string)=?,
        ~dense: option(bool)=?,
        ~raised: option(bool)=?,
        ~unelevated: option(bool)=?,
        ~outlined: option(bool)=?,
        ~theme: option(string)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "dir": Js.Nullable.fromOption(dir),
        "tag": Js.Nullable.fromOption(tag),
        "dense": Js.Nullable.fromOption(dense),
        "raised": Js.Nullable.fromOption(raised),
        "unelevated": Js.Nullable.fromOption(unelevated),
        "outlined": Js.Nullable.fromOption(outlined),
        "theme": Js.Nullable.fromOption(theme),
        "onClick": Js.Nullable.fromOption(onClick),
      },
      children,
    );
};

module ButtonIcon = {
  [@bs.module "rmwc/Button"]
  external reactClass : ReasonReact.reactClass = "ButtonIcon";
  let make = (~use: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"use": Js.Nullable.fromOption(use)},
      children,
    );
};

/* Toolbar */
module Toolbar = {
  [@bs.module "rmwc/Toolbar"]
  external reactClass : ReasonReact.reactClass = "Toolbar";
  let make =
      (
        ~fixed: option(bool)=?,
        ~waterfall: option(bool)=?,
        ~fixedLastrowOnly: option(bool)=?,
        ~flexible: option(bool)=?,
        ~flexibleDefaultBehavior: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "fixed": Js.Nullable.fromOption(fixed),
        "waterfall": Js.Nullable.fromOption(waterfall),
        "fixedLastrowOnly": Js.Nullable.fromOption(fixedLastrowOnly),
        "flexible": Js.Nullable.fromOption(flexible),
        "flexibleDefaultBehavior":
          Js.Nullable.fromOption(flexibleDefaultBehavior),
      },
      children,
    );
};

module ToolbarRow = {
  [@bs.module "rmwc/Toolbar"]
  external reactClass : ReasonReact.reactClass = "ToolbarRow";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module ToolbarSection = {
  [@bs.module "rmwc/Toolbar"]
  external reactClass : ReasonReact.reactClass = "ToolbarSection";
  let make =
      (
        ~alignStart: option(bool)=?,
        ~alignEnd: option(bool)=?,
        ~shrinkToFit: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "alignStart": Js.Nullable.fromOption(alignStart),
        "alignEnd": Js.Nullable.fromOption(alignEnd),
        "shrinkToFit": Js.Nullable.fromOption(shrinkToFit),
      },
      children,
    );
};

module ToolbarTitle = {
  [@bs.module "rmwc/Toolbar"]
  external reactClass : ReasonReact.reactClass = "ToolbarTitle";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module ToolbarMenuIcon = {
  [@bs.module "rmwc/Toolbar"]
  external reactClass : ReasonReact.reactClass = "ToolbarMenuIcon";
  let make =
      (
        ~use: option(string)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "use": Js.Nullable.fromOption(use),
        "onClick": Js.Nullable.fromOption(onClick),
      },
      children,
    );
};

module ToolbarIcon = {
  [@bs.module "rmwc/Toolbar"]
  external reactClass : ReasonReact.reactClass = "ToolbarIcon";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

/* Grid */
module Grid = {
  module Align = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "rmwc/Grid"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~fixedColumnWidth: option(bool)=?,
        ~align: option(Align.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "fixedColumnWidth": Js.Nullable.fromOption(fixedColumnWidth),
        "align": Js.Nullable.fromOption(align |. optionMap(Align.to_string)),
      },
      children,
    );
};

module GridCell = {
  module Align = {
    type t =
      | Top
      | Middle
      | Bottom;
    let to_string =
      fun
      | Top => "top"
      | Middle => "top"
      | Bottom => "bottom";
  };
  [@bs.module "rmwc/Grid"]
  external reactClass : ReasonReact.reactClass = "GridCell";
  let make =
      (
        ~span: option(int)=?,
        ~phone: option(int)=?,
        ~tablet: option(int)=?,
        ~desktop: option(int)=?,
        ~order: option(int)=?,
        ~align: option(Align.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "span": Js.Nullable.fromOption(span),
        "phone": Js.Nullable.fromOption(phone),
        "tablet": Js.Nullable.fromOption(tablet),
        "desktop": Js.Nullable.fromOption(desktop),
        "order": Js.Nullable.fromOption(order),
        "align": Js.Nullable.fromOption(align |. optionMap(Align.to_string)),
      },
      children,
    );
};

/* Typography */
module Typography = {
  module Type = {
    type t =
      | Headline1
      | Headline2
      | Headline3
      | Headline4
      | Headline5
      | Headline6
      | Subtitle1
      | Subtitle2
      | Body1
      | Body2
      | Caption
      | Button
      | Overline;
    let to_string =
      fun
      | Headline1 => "headline1"
      | Headline2 => "headline2"
      | Headline3 => "headline3"
      | Headline4 => "headline4"
      | Headline5 => "headline5"
      | Headline6 => "headline6"
      | Subtitle1 => "subtitle1"
      | Subtitle2 => "subtitle2"
      | Body1 => "body1"
      | Body2 => "body2"
      | Caption => "caption"
      | Button => "button"
      | Overline => "overline";
  };
  [@bs.module "rmwc/Typography"]
  external reactClass : ReasonReact.reactClass = "Typography";
  let make = (~use: option(Type.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "use": Js.Nullable.fromOption(use |. optionMap(Type.to_string)),
      },
      children,
    );
};

/* Drawer */
module Drawer = {
  [@bs.module "rmwc/Drawer"]
  external reactClass : ReasonReact.reactClass = "Drawer";
  let make =
      (
        ~open_: option(bool)=?,
        ~onClose: option(ReactEventRe.Mouse.t => 'a)=?,
        ~onOpen: option(ReactEventRe.Mouse.t => 'a)=?,
        ~permanent: option(bool)=?,
        ~persistent: option(bool)=?,
        ~temporary: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "open": Js.Nullable.fromOption(open_),
        "onClose": Js.Nullable.fromOption(onClose),
        "onOpen": Js.Nullable.fromOption(onOpen),
        "permanent": Js.Nullable.fromOption(permanent),
        "persistent": Js.Nullable.fromOption(persistent),
        "temporary": Js.Nullable.fromOption(temporary),
      },
      children,
    );
};

module DrawerHeader = {
  [@bs.module "rmwc/Drawer"]
  external reactClass : ReasonReact.reactClass = "DrawerHeader";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module DrawerContent = {
  [@bs.module "rmwc/Drawer"]
  external reactClass : ReasonReact.reactClass = "DrawerContent";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

/* List */
module List = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "List";
  let make =
      (
        ~dense: option(bool)=?,
        ~twoLine: option(bool)=?,
        ~avatarList: option(bool)=?,
        ~nonInteractive: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "dense": Js.Nullable.fromOption(dense),
        "twoLine": Js.Nullable.fromOption(twoLine),
        "avatarList": Js.Nullable.fromOption(avatarList),
        "nonInteractive": Js.Nullable.fromOption(nonInteractive),
      },
      children,
    );
};

module ListItem = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "ListItem";
  let make =
      (~selected: option(bool)=?, ~activated: option(bool)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "selected": Js.Nullable.fromOption(selected),
        "activated": Js.Nullable.fromOption(activated),
      },
      children,
    );
};

module ListItemText = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "ListItemText";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module ListItemSecondaryText = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "ListItemSecondaryText";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module ListItemGraphic = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "ListItemGraphic";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module ListItemMeta = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "ListItemMeta";
  let make = (~tag: option(string)=?, ~basename: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "tag": Js.Nullable.fromOption(tag),
        "basename": Js.Nullable.fromOption(basename),
      },
      children,
    );
};

module ListDivider = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "ListDivider";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module ListGroup = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "ListGroup";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module ListGroupSubHeader = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "ListGroupSubHeader";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module SimpleListItem = {
  [@bs.module "rmwc/List"]
  external reactClass : ReasonReact.reactClass = "SimpleListItem";
  let make =
      (
        ~text: option(string)=?,
        ~secondaryText: option(string)=?,
        ~graphic: option(string)=?,
        ~meta: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "text": Js.Nullable.fromOption(text),
        "secondaryText": Js.Nullable.fromOption(secondaryText),
        "graphic": Js.Nullable.fromOption(graphic),
        "meta": Js.Nullable.fromOption(meta),
      },
      children,
    );
};

/* Top App Bar */
module TopAppBar = {
  [@bs.module "rmwc/TopAppBar"]
  external reactClass : ReasonReact.reactClass = "TopAppBar";
  let make =
      (
        ~onNav: option(ReactEventRe.Mouse.t => 'a)=?,
        ~fixed: option(bool)=?,
        ~prominent: option(bool)=?,
        ~short: option(bool)=?,
        ~shortCollapsed: option(bool)=?,
        ~dense: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "onNav": Js.Nullable.fromOption(onNav),
        "fixed": Js.Nullable.fromOption(fixed),
        "prominent": Js.Nullable.fromOption(prominent),
        "short": Js.Nullable.fromOption(short),
        "shortCollapsed": Js.Nullable.fromOption(shortCollapsed),
        "dense": Js.Nullable.fromOption(dense),
      },
      children,
    );
};

module TopAppBarRow = {
  [@bs.module "rmwc/TopAppBar"]
  external reactClass : ReasonReact.reactClass = "TopAppBarRow";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module TopAppBarSection = {
  [@bs.module "rmwc/TopAppBar"]
  external reactClass : ReasonReact.reactClass = "TopAppBarSection";
  let make =
      (~alignStart: option(bool)=?, ~alignEnd: option(bool)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "alignStart": Js.Nullable.fromOption(alignStart),
        "alignEnd": Js.Nullable.fromOption(alignEnd),
      },
      children,
    );
};

module TopAppBarTitle = {
  [@bs.module "rmwc/TopAppBar"]
  external reactClass : ReasonReact.reactClass = "TopAppBarTitle";
  let make = (~tag: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"tag": Js.Nullable.fromOption(tag)},
      children,
    );
};

module TopAppBarNavigationIcon = {
  [@bs.module "rmwc/TopAppBar"]
  external reactClass : ReasonReact.reactClass = "TopAppBarNavigationIcon";
  let make =
      (
        ~use: option(string)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "use": Js.Nullable.fromOption(use),
        "onClick": Js.Nullable.fromOption(onClick),
      },
      children,
    );
};

module TopAppBarActionItem = {
  [@bs.module "rmwc/TopAppBar"]
  external reactClass : ReasonReact.reactClass = "TopAppBarActionItem";
  let make =
      (
        ~tag: option(string)=?,
        ~href: option(string)=?,
        ~use: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "tag": Js.Nullable.fromOption(tag),
        "href": Js.Nullable.fromOption(href),
        "use": Js.Nullable.fromOption(use),
      },
      children,
    );
};