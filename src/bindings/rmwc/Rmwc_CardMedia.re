open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  square: Js.nullable(bool),
  sixteenByNine: Js.nullable(bool),
};
[@bs.module "rmwc/Card"]
external reactClass : ReasonReact.reactClass = "CardMedia";
let make = (~square=?, ~sixteenByNine=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~square=square |. fromOption,
        ~sixteenByNine=sixteenByNine |. fromOption,
      ),
    children,
  );