module Align = {
  type t =
    | Left
    | Right;
  let to_string =
    fun
    | Left => "left"
    | Right => "right";
};

[@bs.deriving abstract]
type jsProps = {
  fixedColumnWidth: Js.nullable(bool),
  align: Js.nullable(Align.t),
};

[@bs.module "rmwc/Grid"]
external reactClass : ReasonReact.reactClass = "Grid";
let make = (~fixedColumnWidth=?, ~align=?,  children) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=jsProps(
    ~fixedColumnWidth= fixedColumnWidth |. Js.Nullable.fromOption,
    ~align= align |. Js.Nullable.fromOption
  ),
  children,
);