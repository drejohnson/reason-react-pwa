[@bs.module "rmwc/List"]
external reactClass : ReasonReact.reactClass = "ListGroup";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);