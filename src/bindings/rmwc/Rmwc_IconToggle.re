open Rmwc_Utils;

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
  checked: Js.nullable(bool),
  disabled: Js.nullable(bool),
  onChange:
    Js.nullable(ReactEventRe.Mouse.t => {. "detail": {. "isOn": bool}}),
  theme: Js.nullable(string),
};

[@bs.module "rmwc/IconToggle"]
external reactClass : ReasonReact.reactClass = "IconToggle";
let make =
    (~on=?, ~off=?, ~checked=?, ~disabled=?, ~onChange=?, ~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~on=on |. fromOption,
        ~off=off |. fromOption,
        ~checked=checked |. fromOption,
        ~disabled=disabled |. fromOption,
        ~onChange=onChange |. fromOption,
        ~theme=theme |. fromOption,
      ),
    children,
  );