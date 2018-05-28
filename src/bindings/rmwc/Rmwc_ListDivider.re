[@bs.module "rmwc/List"]
external reactClass : ReasonReact.reactClass = "ListDivider";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);