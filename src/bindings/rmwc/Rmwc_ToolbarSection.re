open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  alignStart: Js.nullable(bool),
  alignEnd: Js.nullable(bool),
  shrinkToFit: Js.nullable(bool),
};

[@bs.module "rmwc/Toolbar"]
external reactClass : ReasonReact.reactClass = "ToolbarSection";
let make = (~alignStart=?, ~alignEnd=?, ~shrinkToFit=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~alignStart=alignStart |. fromOption,
        ~alignEnd=alignEnd |. fromOption,
        ~shrinkToFit=shrinkToFit |. fromOption,
      ),
    children,
  );