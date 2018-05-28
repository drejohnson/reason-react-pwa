open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  dir: Js.nullable(string),
  tag: Js.nullable(tag),
  dense: Js.nullable(bool),
  raised: Js.nullable(bool),
  unelevated: Js.nullable(bool),
  outlined: Js.nullable(bool),
  theme: Js.nullable(string),
  onClick: Js.nullable(ReactEventRe.Mouse.t => unit)
};

[@bs.module "rmwc/Button"]
external reactClass : ReasonReact.reactClass = "Button";
let make =
    (
      ~dir=?,
      ~tag=?,
      ~dense=?,
      ~raised=?,
      ~unelevated=?,
      ~outlined=?,
      ~theme=?,
      ~onClick=?,
      children,
    ) => 
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=jsProps(
      ~dir= dir |. fromOption,
      ~tag= tag |. fromOption,
      ~dense= dense |. fromOption,
      ~raised= raised |. fromOption,
      ~unelevated= unelevated |. fromOption,
      ~outlined= outlined |. fromOption,
      ~theme= theme |. fromOption,
      ~onClick= onClick |. fromOption,
    ),
    children,
  );