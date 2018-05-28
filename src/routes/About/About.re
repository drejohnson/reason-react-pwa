let component = ReasonReact.statelessComponent("About");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <title> ("About" |> Utils.string_) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <section>
        <Rmwc.Typography use=Headline2>
          ("About component" |> Utils.string_)
        </Rmwc.Typography>
      </section>
    </Fragment>,
};