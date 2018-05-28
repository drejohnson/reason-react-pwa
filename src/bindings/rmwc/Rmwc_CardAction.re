open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  icon: Js.nullable(bool),
  iconToggle: Js.nullable(bool),
};
[@bs.module "rmwc/Card"]
external reactClass : ReasonReact.reactClass = "CardAction";
let make = (~icon=?, ~iconToggle=?, children) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=jsProps(
    ~icon= icon |. fromOption,
    ~iconToggle= iconToggle |. fromOption
  ),
  children,
);