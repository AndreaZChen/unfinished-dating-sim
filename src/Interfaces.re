module type Scene = {
  let id: string;

  let backgroundColorHex: string;

  let title: string;

  let renderer:
    (
      ~globalState: GlobalState.t,
      ~globalDispatch: GlobalState.action => unit
    ) =>
    React.element;
};