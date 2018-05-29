open Rmwc_Utils;

[@bs.deriving abstract]
type toggle = {
  label: string,
  content: string,
};

[@bs.deriving abstract]
type jsProps = {
  on:
    Js.nullable(
      {
        .
        "label": string,
        "content": string,
      },
    ),
  off:
    Js.nullable(
      {
        .
        "label": string,
        "content": string,
      },
    ),
  onChange: Js.nullable(ReactEventRe.Mouse.t => unit),
  theme: Js.nullable(string),
};

[@bs.module "rmwc/IconToggle"]
external reactClass : ReasonReact.reactClass = "IconToggle";
let make = (~on=?, ~off=?, ~onChange=?, ~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~on=on |. fromOption,
        ~off=off |. fromOption,
        ~onChange=onChange |. fromOption,
        ~theme=theme |. fromOption,
      ),
    children,
  );