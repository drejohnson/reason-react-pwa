let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <title> ("ReasonReact PWA" |> Utils.string_) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <section>
        <Rmwc.Typography use=Headline2>
          ("Home component" |> Utils.string_)
        </Rmwc.Typography>
      </section>
    </Fragment>,
};