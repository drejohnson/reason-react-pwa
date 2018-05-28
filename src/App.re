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
      <Rmwc.TopAppBar fixed=true onNav=((_) => send(ToggleDrawer))>
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
        <Rmwc.Grid> <Rmwc.GridCell span=12> <Counter /> </Rmwc.GridCell> </Rmwc.Grid>
        <Rmwc.Grid>
          <Rmwc.GridCell tablet=6 desktop=4>
            ("Grid Cell 1" |> Utils.string_)
          </Rmwc.GridCell>
          <Rmwc.GridCell tablet=6 desktop=4>
            ("Grid Cell 2" |> Utils.string_)
          </Rmwc.GridCell>
          <Rmwc.GridCell desktop=4> ("Grid Cell 3" |> Utils.string_) </Rmwc.GridCell>
        </Rmwc.Grid>
        <Rmwc.Grid>
          <Rmwc.GridCell>
            <nav>
              <Router.Link route=Home>
                <Rmwc.Typography use=Button> ("Home" |> Utils.string_) </Rmwc.Typography>
              </Router.Link>
              <Router.Link route=About>
                <Rmwc.Typography use=Button>
                  ("About" |> Utils.string_)
                </Rmwc.Typography>
              </Router.Link>
            </nav>
          </Rmwc.GridCell>
        </Rmwc.Grid>
        <Rmwc.Grid>
          <Rmwc.GridCell>
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
          </Rmwc.GridCell>
        </Rmwc.Grid>
      </main>
      <Rmwc.Drawer
        temporary=true
        open_=state.drawerOpen
        onClose=((_) => send(CloseDrawer))>
        <Rmwc.DrawerContent>
          <Rmwc.ListItem>
            <Rmwc.ListItemText> ("Item 1" |> Utils.string_) </Rmwc.ListItemText>
          </Rmwc.ListItem>
          <Rmwc.ListItem>
            <Rmwc.ListItemText> ("Item 2" |> Utils.string_) </Rmwc.ListItemText>
          </Rmwc.ListItem>
          <Rmwc.ListItem>
            <Rmwc.ListItemText> ("Item 3" |> Utils.string_) </Rmwc.ListItemText>
          </Rmwc.ListItem>
        </Rmwc.DrawerContent>
      </Rmwc.Drawer>
    </Fragment>,
};