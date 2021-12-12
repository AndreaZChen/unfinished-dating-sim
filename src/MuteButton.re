module Styles = {
  open Css;

  let button = style([marginLeft(`px(10)), userSelect(`none)]);
};

[@react.component]
let make = (~isSoundMuted, ~globalDispatch: GlobalState.action => unit) => {
  let onClick =
    React.useCallback1(
      _ => globalDispatch(GlobalState.MuteButtonClicked),
      [|globalDispatch|],
    );

  let onKeyDown =
    React.useCallback0(event => {ReactEvent.Keyboard.stopPropagation(event)});

  <button className=Styles.button onClick onKeyDown>
    {React.string(isSoundMuted ? {j|🔇|j} : {j|🔊|j})}
  </button>;
};
