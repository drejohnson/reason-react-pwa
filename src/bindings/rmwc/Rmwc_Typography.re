open Rmwc_Utils;

module Type = {
  type t =
    | Headline1
    | Headline2
    | Headline3
    | Headline4
    | Headline5
    | Headline6
    | Subtitle1
    | Subtitle2
    | Body1
    | Body2
    | Caption
    | Button
    | Overline;
  let to_string =
    fun
    | Headline1 => "headline1"
    | Headline2 => "headline2"
    | Headline3 => "headline3"
    | Headline4 => "headline4"
    | Headline5 => "headline5"
    | Headline6 => "headline6"
    | Subtitle1 => "subtitle1"
    | Subtitle2 => "subtitle2"
    | Body1 => "body1"
    | Body2 => "body2"
    | Caption => "caption"
    | Button => "button"
    | Overline => "overline";
};

[@bs.deriving abstract]
type jsProps = {
  tag: Js.nullable(string),
  use: Js.nullable(string),
  theme: Js.nullable(string),
  style: Js.nullable(ReactDOMRe.Style.t),
};
[@bs.module "rmwc/Typography"]
external reactClass : ReasonReact.reactClass = "Typography";
let make = (~tag=?, ~use=?, ~theme=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      jsProps(
        ~tag=tag |. fromOption,
        ~use=use |. optionMap(Type.to_string) |. fromOption,
        ~theme=theme |. fromOption,
        ~style=style |. fromOption,
      ),
    children,
  );