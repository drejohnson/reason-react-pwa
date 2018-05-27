open Utils;

open MaterialWebComponents;

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
      <TopAppBar fixed=true onNav=((_) => send(ToggleDrawer))>
        <TopAppBarRow>
          <TopAppBarSection alignStart=true>
            <TopAppBarNavigationIcon use="menu" />
            <TopAppBarTitle tag="h1">
              ("Hello " ++ name |> string_)
            </TopAppBarTitle>
          </TopAppBarSection>
          <TopAppBarSection alignEnd=true>
            <TopAppBarActionItem
              tag="a"
              href="https://reasonml.github.io/reason-react/"
              use="favorite"
            />
          </TopAppBarSection>
        </TopAppBarRow>
      </TopAppBar>
      <main role="main" style=(ReactDOMRe.Style.make(~paddingTop="64px", ()))>
        <Grid> <GridCell span=12> <Counter /> </GridCell> </Grid>
        <Grid>
          <GridCell tablet=6 desktop=4>
            ("Grid Cell 1" |> Utils.string_)
          </GridCell>
          <GridCell tablet=6 desktop=4>
            ("Grid Cell 2" |> Utils.string_)
          </GridCell>
          <GridCell desktop=4> ("Grid Cell 3" |> Utils.string_) </GridCell>
        </Grid>
        <Grid>
          <GridCell>
            <nav>
              <Router.Link route=Home>
                <Typography use=Button> ("Home" |> Utils.string_) </Typography>
              </Router.Link>
              <Router.Link route=About>
                <Typography use=Button>
                  ("About" |> Utils.string_)
                </Typography>
              </Router.Link>
            </nav>
          </GridCell>
        </Grid>
        <Grid>
          <GridCell>
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
          </GridCell>
        </Grid>
      </main>
      <Drawer
        temporary=true
        open_=state.drawerOpen
        onClose=((_) => send(CloseDrawer))>
        <DrawerContent>
          <ListItem>
            <ListItemText> ("Item 1" |> Utils.string_) </ListItemText>
          </ListItem>
          <ListItem>
            <ListItemText> ("Item 2" |> Utils.string_) </ListItemText>
          </ListItem>
          <ListItem>
            <ListItemText> ("Item 3" |> Utils.string_) </ListItemText>
          </ListItem>
        </DrawerContent>
      </Drawer>
    </Fragment>,
};