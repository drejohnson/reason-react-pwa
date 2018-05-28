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
        <Rmwc.Grid>
          <Rmwc.GridCell span=12>
            <Rmwc.Typography
              use=Headline2
              tag="h2"
              style=(ReactDOMRe.Style.make(~padding="1rem", ()))>
              ("About" |> Utils.string_)
            </Rmwc.Typography>
          </Rmwc.GridCell>
        </Rmwc.Grid>
      </section>
    </Fragment>,
};