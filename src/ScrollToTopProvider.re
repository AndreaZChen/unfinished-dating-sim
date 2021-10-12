let context = React.createContext(() => ());

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};

let make = React.Context.provider(context);

let useScrollToTop = () => React.useContext(context);