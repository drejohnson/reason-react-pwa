[@bs.module "rmwc/TopAppBar"]
external reactClass : ReasonReact.reactClass = "TopAppBarRow";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);