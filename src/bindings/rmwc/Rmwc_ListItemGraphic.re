[@bs.module "rmwc/List"]
external reactClass : ReasonReact.reactClass = "ListItemGraphic";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);