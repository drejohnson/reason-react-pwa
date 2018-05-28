open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  tag: Js.nullable(string),
  href: Js.nullable(string),
  use: Js.nullable(string),
};

[@bs.module "rmwc/TopAppBar"]
  external reactClass : ReasonReact.reactClass = "TopAppBarActionItem";
  let make =
      (
        ~tag=?,
        ~href=?,
        ~use=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=jsProps(
        ~tag= tag |. fromOption,
        ~href= href |. fromOption,
        ~use= use |. fromOption,
      ),
      children,
    );