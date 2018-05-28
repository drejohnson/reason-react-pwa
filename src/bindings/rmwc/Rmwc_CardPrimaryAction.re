[@bs.module "rmwc/Card"]
external reactClass : ReasonReact.reactClass = "CardPrimaryAction";
let make = children =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=Js.Obj.empty(),
  children,
);