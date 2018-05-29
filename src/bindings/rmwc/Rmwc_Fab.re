open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  mini: Js.nullable(bool),
  exited: Js.nullable(bool),
  cssOnly: Js.nullable(bool),
  theme: Js.nullable(string),
};
[@bs.module "rmwc/Fab"] external reactClass : ReasonReact.reactClass = "Fab";
let make = (~mini=?, ~exited=?, ~cssOnly=?, ~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~mini=mini |. Js.Nullable.fromOption,
        ~exited=exited |. Js.Nullable.fromOption,
        ~cssOnly=cssOnly |. Js.Nullable.fromOption,
        ~theme=theme |. Js.Nullable.fromOption,
      ),
    children,
  );