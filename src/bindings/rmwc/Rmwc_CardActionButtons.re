[@bs.module "rmwc/Card"]
external reactClass : ReasonReact.reactClass = "CardActionButtons";
let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);