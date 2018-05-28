module Align = {
  type t =
    | Top
    | Middle
    | Bottom;
  let to_string =
    fun
    | Top => "top"
    | Middle => "top"
    | Bottom => "bottom";
};

[@bs.deriving abstract]
type jsProps = {
  span: Js.nullable(int),
  phone: Js.nullable(int),
  tablet: Js.nullable(int),
  desktop: Js.nullable(int),
  order: Js.nullable(int),
  align: Js.nullable(Align.t),
};
[@bs.module "rmwc/Grid"]
external reactClass : ReasonReact.reactClass = "GridCell";
let make = (
  ~span=?,
  ~phone=?,
  ~tablet=?,
  ~desktop=?,
  ~order=?,
  ~align=?, 
  children
) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=jsProps(
    ~span= span |. Js.Nullable.fromOption,
    ~phone= phone |. Js.Nullable.fromOption,
    ~tablet=  tablet |. Js.Nullable.fromOption,
    ~desktop= desktop |. Js.Nullable.fromOption,
    ~order= order |. Js.Nullable.fromOption,
    ~align= align |. Js.Nullable.fromOption,
  ),
  children,
);