[@bs.module "rmwc/Drawer"]
external reactClass : ReasonReact.reactClass = "DrawerHeader";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);