open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  fullbleed: Js.nullable(bool),
};
[@bs.module "rmwc/Card"]
external reactClass : ReasonReact.reactClass = "CardActions";
let make = (~fullbleed=?, children) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=jsProps(~fullbleed= fullbleed |. fromOption),
  children,
);