[@bs.module "rmwc/Toolbar"]
external reactClass : ReasonReact.reactClass = "ToolbarIcon";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);