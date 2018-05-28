open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  onNav: Js.nullable(ReactEventRe.Mouse.t => unit),
  fixed: Js.nullable(bool),
  prominent: Js.nullable(bool),
  short: Js.nullable(bool),
  shortCollapsed: Js.nullable(bool),
  dense: Js.nullable(bool),
};

[@bs.module "rmwc/TopAppBar"]
external reactClass : ReasonReact.reactClass = "TopAppBar";
let make =
    (
      ~onNav=?,
      ~fixed=?,
      ~prominent=?,
      ~short=?,
      ~shortCollapsed=?,
      ~dense=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~onNav=onNav |. fromOption,
        ~fixed=fixed |. fromOption,
        ~prominent=prominent |. fromOption,
        ~short=short |. fromOption,
        ~shortCollapsed=shortCollapsed |. fromOption,
        ~dense=dense |. fromOption,
      ),
    children,
  );