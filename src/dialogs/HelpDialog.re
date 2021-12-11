module Styles = {
  open Css;

  let buttonsArea =
    style([
      width(`percent(100.)),
      display(`flex),
      flexWrap(`wrap),
      justifyContent(`spaceAround),
      alignItems(`center),
      borderTop(`px(1), `solid, `hex(CommonStyles.defaultBorderHex)),
      paddingTop(`px(10)),
      marginTop(`px(10)),
    ]);
};

let helpText = {js|INSTRUCTIONS:

Click/touch inside the text box to advance the text. When presented with a choice, click/touch your preferred option it to select it.

Alternatively, use Space or Enter to advance, and the arrow keys to highlight a choice when prompted.

Ⓒ 2021 Andrea Zonghao Chen|js};

[@react.component]
let make = (~onClose: unit => unit) => {
  let _resetLocalStorage =
    React.useCallback0(_ => {
      Dom.Storage.clear(Dom.Storage.localStorage);
      Webapi.Dom.location->Webapi.Dom.Location.reloadWithForce;
    });

  <Dialog onClose>
    <Text> helpText </Text>
    <br />
    <Text customColorHex=CommonStyles.commentHex>
      "// TODO: add settings? save/load system?"
    </Text>
    <div className=Styles.buttonsArea>
      <button onClick={_ => onClose()}> {React.string("Close")} </button>
    </div>
  </Dialog>;
};
