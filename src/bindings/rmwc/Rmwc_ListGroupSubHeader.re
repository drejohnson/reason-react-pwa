[@bs.module "rmwc/List"]
external reactClass : ReasonReact.reactClass = "ListGroupSubHeader";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);