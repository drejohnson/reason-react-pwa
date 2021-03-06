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
        <Rmwc.Grid>
          <Rmwc.GridCell span=12>
            <Rmwc.Typography
              use=Headline2
              tag="h2"
              style=(ReactDOMRe.Style.make(~padding="1rem", ()))>
              ("Home component" |> Utils.string_)
            </Rmwc.Typography>
          </Rmwc.GridCell>
          <Rmwc.IconToggle
            on={"label": "Remove from favorites", "content": "favorite"}
            off={"label": "Add to favorites", "content": "favorite_border"}
          />
          <Rmwc.Fab> ("favorite" |> Utils.string_) </Rmwc.Fab>
        </Rmwc.Grid>
        <Counter />
        <Rmwc.Grid>
          <Rmwc.GridCell tablet=4 desktop=4>
            <Rmwc.Card
              outlined=true
              style=(ReactDOMRe.Style.make(~marginTop="1rem", ()))>
              <div style=(ReactDOMRe.Style.make(~padding="1rem", ()))>
                <Rmwc.Typography use=Headline3 tag="h3">
                  ("Hello World Card" |> Utils.string_)
                </Rmwc.Typography>
                <Rmwc.Typography
                  use=Body1
                  tag="p"
                  theme="text-secondary-on-background"
                  style=(ReactDOMRe.Style.make(~marginTop="1rem", ()))>
                  (
                    "Normcore kickstarter live-edge hammock cliche DIY hashtag. Green juice messenger bag woke bicycle rights chartreuse"
                    |> Utils.string_
                  )
                </Rmwc.Typography>
              </div>
            </Rmwc.Card>
          </Rmwc.GridCell>
          <Rmwc.GridCell tablet=4 desktop=4>
            <Rmwc.Card
              outlined=true
              style=(ReactDOMRe.Style.make(~marginTop="1rem", ()))>
              <div style=(ReactDOMRe.Style.make(~padding="1rem", ()))>
                <Rmwc.Typography use=Headline3 tag="h3">
                  ("Hello World Card" |> Utils.string_)
                </Rmwc.Typography>
                <Rmwc.Typography
                  use=Body1
                  tag="p"
                  theme="text-secondary-on-background"
                  style=(ReactDOMRe.Style.make(~marginTop="1rem", ()))>
                  (
                    "Normcore kickstarter live-edge hammock cliche DIY hashtag. Green juice messenger bag woke bicycle rights chartreuse"
                    |> Utils.string_
                  )
                </Rmwc.Typography>
              </div>
            </Rmwc.Card>
          </Rmwc.GridCell>
          <Rmwc.GridCell tablet=4 desktop=4>
            <Rmwc.Card
              outlined=true
              style=(ReactDOMRe.Style.make(~marginTop="1rem", ()))>
              <div style=(ReactDOMRe.Style.make(~padding="1rem", ()))>
                <Rmwc.Typography use=Headline3 tag="h3">
                  ("Hello World Card" |> Utils.string_)
                </Rmwc.Typography>
                <Rmwc.Typography
                  use=Body1
                  tag="p"
                  theme="text-secondary-on-background"
                  style=(ReactDOMRe.Style.make(~marginTop="1rem", ()))>
                  (
                    "Normcore kickstarter live-edge hammock cliche DIY hashtag. Green juice messenger bag woke bicycle rights chartreuse"
                    |> Utils.string_
                  )
                </Rmwc.Typography>
              </div>
            </Rmwc.Card>
          </Rmwc.GridCell>
        </Rmwc.Grid>
      </section>
    </Fragment>,
};