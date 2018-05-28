open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {use: Js.nullable(string)};

[@bs.module "rmwc/Button"]
external reactClass : ReasonReact.reactClass = "ButtonIcon";
let make = (~use=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=jsProps(~use=use |. fromOption),
    children,
  );