open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  tag: Js.nullable(tag),
  basename: Js.nullable(string),
};
[@bs.module "rmwc/List"]
external reactClass : ReasonReact.reactClass = "ListItemMeta";
let make = (~tag=?, ~basename=?, children) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=jsProps(
    ~tag= tag |. Js.Nullable.fromOption,
    ~basename= basename |. Js.Nullable.fromOption
  ),
  children,
);