[@bs.module "rmwc/Drawer"]
external reactClass : ReasonReact.reactClass = "DrawerContent";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);