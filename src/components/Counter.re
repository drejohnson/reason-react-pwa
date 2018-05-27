open Utils;

open MaterialWebComponents;

type state = {count: int};

type action =
  | Increase
  | Decrease;

let component = ReasonReact.reducerComponent("Counter");

let make = _children => {
  ...component,
  initialState: () => {count: 0},
  reducer: (action, state) =>
    switch (action) {
    | Increase => ReasonReact.Update({count: state.count + 1})
    | Decrease => ReasonReact.Update({count: state.count - 1})
    },
  render: ({state, send}) =>
    <div>
      <h1> (string_of_int(state.count) |> string_) </h1>
      <Button outlined=true onClick=((_) => send(Increase))>
        <ButtonIcon use="add" />
        ("Increment" |> string_)
      </Button>
      <Button outlined=true onClick=((_) => send(Decrease))>
        <ButtonIcon use="remove" />
        ("Decrement" |> string_)
      </Button>
    </div>,
};