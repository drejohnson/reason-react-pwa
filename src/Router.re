module Config = {
  type route =
    | Home
    | About
    | NotFound;
  let routeFromUrl = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | [] => Home
    | ["about"] => About
    | _ => NotFound
    };
  let routeToUrl = (route: route) =>
    switch (route) {
    | Home => "/"
    | About => "/about"
    | NotFound => ""
    };
  let routeToTitle = route =>
    switch (route) {
    | Home => "Home"
    | About => "About"
    | NotFound => "Not Found"
    };
};

include ReRoute.CreateRouter(Config);