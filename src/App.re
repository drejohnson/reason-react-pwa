open Utils;

type state = {drawerOpen: bool};

type action =
  | ToggleDrawer
  | CloseDrawer;

let component = ReasonReact.reducerComponent("App");

let make = (~name, _children) => {
  ...component,
  initialState: () => {drawerOpen: false},
  reducer: (action, state) =>
    switch (action) {
    | ToggleDrawer => ReasonReact.Update({drawerOpen: ! state.drawerOpen})
    | CloseDrawer => ReasonReact.Update({drawerOpen: false})
    },
  render: ({state, send}) =>
    <Fragment>
      <ReactHelmet>
        <title> ("ReasonReact PWA" |> Utils.string_) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <Rmwc.TopAppBar fixed=true onNav=(_ => send(ToggleDrawer))>
        <Rmwc.TopAppBarRow>
          <Rmwc.TopAppBarSection alignStart=true>
            <Rmwc.TopAppBarNavigationIcon use="menu" />
            <Rmwc.TopAppBarTitle tag="h1">
              ("Hello " ++ name |> string_)
            </Rmwc.TopAppBarTitle>
          </Rmwc.TopAppBarSection>
          <Rmwc.TopAppBarSection alignEnd=true>
            <Rmwc.TopAppBarActionItem
              tag="a"
              href="https://reasonml.github.io/reason-react/"
              use="favorite"
            />
          </Rmwc.TopAppBarSection>
        </Rmwc.TopAppBarRow>
      </Rmwc.TopAppBar>
      <main role="main" style=(ReactDOMRe.Style.make(~paddingTop="64px", ()))>
        <Rmwc.Grid>
          <Rmwc.GridCell>
            <nav>
              <Router.Link route=Home>
                <Rmwc.Typography use=Button>
                  ("Home" |> Utils.string_)
                </Rmwc.Typography>
              </Router.Link>
              <Router.Link route=About>
                <Rmwc.Typography use=Button>
                  ("About" |> Utils.string_)
                </Rmwc.Typography>
              </Router.Link>
            </nav>
          </Rmwc.GridCell>
        </Rmwc.Grid>
        <Router.Container>
          ...(
               (~currentRoute) =>
                 switch (currentRoute) {
                 | Home => <LazyHome />
                 | About => <LazyAbout />
                 | _ => <LazyNotFound />
                 }
             )
        </Router.Container>
      </main>
      <Rmwc.Drawer
        temporary=true
        open_=state.drawerOpen
        onClose=(_ => send(CloseDrawer))>
        <Rmwc.DrawerContent>
          <Rmwc.ListItem>
            <Rmwc.ListItemText>
              ("Item 1" |> Utils.string_)
            </Rmwc.ListItemText>
          </Rmwc.ListItem>
          <Rmwc.ListItem>
            <Rmwc.ListItemText>
              ("Item 2" |> Utils.string_)
            </Rmwc.ListItemText>
          </Rmwc.ListItem>
          <Rmwc.ListItem>
            <Rmwc.ListItemText>
              ("Item 3" |> Utils.string_)
            </Rmwc.ListItemText>
          </Rmwc.ListItem>
        </Rmwc.DrawerContent>
      </Rmwc.Drawer>
    </Fragment>,
};