open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  [@bs.as "open"]
  open_: Js.nullable(bool),
  onClose: Js.nullable(ReactEventRe.Mouse.t => unit),
  onOpen: Js.nullable(ReactEventRe.Mouse.t => unit),
  permanent: Js.nullable(bool),
  persistent: Js.nullable(bool),
  temporary: Js.nullable(bool),
};

[@bs.module "rmwc/Drawer"]
external reactClass : ReasonReact.reactClass = "Drawer";
let make =
    (
      ~open_=?,
      ~onClose=?,
      ~onOpen=?,
      ~permanent=?,
      ~persistent=?,
      ~temporary=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~open_=open_ |. fromOption,
        ~onClose=onClose |. fromOption,
        ~onOpen=onOpen |. fromOption,
        ~permanent=permanent |. fromOption,
        ~persistent=persistent |. fromOption,
        ~temporary=temporary |. fromOption,
      ),
    children,
  );