open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  text: Js.nullable(string),
  secondaryText: Js.nullable(string),
  graphic: Js.nullable(string),
  meta: Js.nullable(string),
};
[@bs.module "rmwc/List"]
external reactClass : ReasonReact.reactClass = "SimpleListItem";
let make = (
  ~text=?,
  ~secondaryText=?,
  ~graphic=?,
  ~meta=?, 
  children
) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=jsProps(
    ~text= text |. fromOption,
    ~secondaryText= secondaryText |. fromOption,
    ~graphic= graphic |. fromOption,
    ~meta= meta |. fromOption,
  ),
  children,
);