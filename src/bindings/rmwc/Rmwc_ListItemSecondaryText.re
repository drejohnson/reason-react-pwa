[@bs.module "rmwc/List"]
external reactClass : ReasonReact.reactClass = "ListItemSecondaryText";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);