type tag = [ | `Str(string) | `ReactClass(ReasonReact.reactClass)];

type any;

external any : 'a => any = "%identify";

let fromOption = Js.Nullable.fromOption;

let optionMap = (option, fn) => Belt.Option.map(option, fn);