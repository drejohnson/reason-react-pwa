let component = ReasonReact.statelessComponent("NotFound");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <title> ("Page Not Found" |> Utils.string_) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <section> 
        <Rmwc.Typography use=Headline2>
          ("Not Fount component" |> Utils.string_)
        </Rmwc.Typography>
      </section>
    </Fragment>,
};