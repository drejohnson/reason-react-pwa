open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  use: Js.nullable(string),
  onClick: Js.nullable(ReactEventRe.Mouse.t => unit),
};

[@bs.module "rmwc/Toolbar"]
external reactClass : ReasonReact.reactClass = "ToolbarMenuIcon";
let make = (~use=?, ~onClick=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=jsProps(~use=use |. fromOption, ~onClick=onClick |. fromOption),
    children,
  );