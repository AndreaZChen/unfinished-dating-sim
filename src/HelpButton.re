module Styles = {
  open Css;

  let helpButton = style([userSelect(`none)]);
};

[@react.component]
let make = (~globalDispatch: GlobalState.action => unit) => {
  let onClick =
    React.useCallback1(
      _ => globalDispatch(GlobalState.HelpDialogOpened),
      [|globalDispatch|],
    );

  let onKeyDown =
    React.useCallback0(event => {ReactEvent.Keyboard.stopPropagation(event)});

  <button className=Styles.helpButton onClick onKeyDown>
    {React.string("?")}
  </button>;
};
