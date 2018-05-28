open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  alignStart: Js.nullable(bool),
  alignEnd: Js.nullable(bool),
};

[@bs.module "rmwc/TopAppBar"]
external reactClass : ReasonReact.reactClass = "TopAppBarSection";
let make =
    (
      ~alignStart=?,
      ~alignEnd=?,
      children,
    ) => 
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=jsProps(
      ~alignStart= alignStart |. fromOption,
      ~alignEnd= alignEnd |. fromOption,
    ),
    children,
  );