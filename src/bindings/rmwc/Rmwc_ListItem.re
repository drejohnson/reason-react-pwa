open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  selected: Js.nullable(bool),
  activated: Js.nullable(bool),
};
[@bs.module "rmwc/List"]
external reactClass : ReasonReact.reactClass = "ListItem";
let make = (~selected=?, ~activated=?, children) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=jsProps(
    ~selected= selected |. fromOption,
    ~activated= activated |. fromOption,
  ),
  children,
);