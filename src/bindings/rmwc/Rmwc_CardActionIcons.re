[@bs.module "rmwc/Card"]
external reactClass : ReasonReact.reactClass = "CardActionIcons";
let make = children =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=Js.Obj.empty(),
  children,
);