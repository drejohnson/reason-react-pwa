open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {tag: Js.nullable(string)};

[@bs.module "rmwc/TopAppBar"]
external reactClass : ReasonReact.reactClass = "TopAppBarTitle";
let make = (~tag=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=jsProps(~tag=tag |. fromOption),
    children,
  );