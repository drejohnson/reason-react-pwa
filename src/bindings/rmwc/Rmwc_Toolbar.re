open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  fixed: Js.nullable(bool),
  waterfall: Js.nullable(bool),
  fixedLastrowOnly: Js.nullable(bool),
  flexible: Js.nullable(bool),
  flexibleDefaultBehavior: Js.nullable(bool),
};

[@bs.module "rmwc/Toolbar"]
external reactClass : ReasonReact.reactClass = "Toolbar";
let make =
    (
      ~fixed=?,
      ~waterfall=?,
      ~fixedLastrowOnly=?,
      ~flexible=?,
      ~flexibleDefaultBehavior=?,
      children,
    ) => 
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=jsProps(
      ~fixed= fixed |. fromOption,
      ~waterfall= waterfall |. fromOption,
      ~fixedLastrowOnly= fixedLastrowOnly |. fromOption,
      ~flexible= flexible |. fromOption,
      ~flexibleDefaultBehavior= flexibleDefaultBehavior |. fromOption,
    ),
    children,
  );