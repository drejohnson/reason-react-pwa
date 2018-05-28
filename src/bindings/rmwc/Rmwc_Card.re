open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  outlined: Js.nullable(bool),
  style: Js.nullable(ReactDOMRe.Style.t),
};
[@bs.module "rmwc/Card"]
external reactClass : ReasonReact.reactClass = "Card";
let make = (~outlined=?, ~style=?, children) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=jsProps(
    ~outlined= outlined |. fromOption,
    ~style= style |. fromOption,
  ),
  children,
);