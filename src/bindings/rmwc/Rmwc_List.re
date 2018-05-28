open Rmwc_Utils;

[@bs.deriving abstract]
type jsProps = {
  dense: Js.nullable(bool),
  twoLine: Js.nullable(bool),
  avatarList: Js.nullable(bool),
  nonInteractive: Js.nullable(bool),
};
[@bs.module "rmwc/List"] external reactClass : ReasonReact.reactClass = "List";
let make = (~dense=?, ~twoLine=?, ~avatarList=?, ~nonInteractive=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~dense=dense |. fromOption,
        ~twoLine=twoLine |. fromOption,
        ~avatarList=avatarList |. fromOption,
        ~nonInteractive=nonInteractive |. fromOption,
      ),
    children,
  );