open Utils;

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
      <Rmwc.Button outlined=true onClick=((_) => send(Increase))>
        <Rmwc.ButtonIcon use="add" />
        ("Increment" |> string_)
      </Rmwc.Button>
      <Rmwc.Button outlined=true onClick=((_) => send(Decrease))>
        <Rmwc.ButtonIcon use="remove" />
        ("Decrement" |> string_)
      </Rmwc.Button>
    </div>,
};