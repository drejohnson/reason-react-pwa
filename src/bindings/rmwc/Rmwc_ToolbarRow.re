[@bs.module "rmwc/Toolbar"]
external reactClass : ReasonReact.reactClass = "ToolbarRow";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);