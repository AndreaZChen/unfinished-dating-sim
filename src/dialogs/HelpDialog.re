let helpText = {js|INSTRUCTIONS:

Playing this game is fairly straightforward! Simply click on the buttons to advance the story in the indicated way. There may be other ways to progress, if you keep an eye out.

Ⓒ 2020 Andrea Zonghao Chen|js};


[@react.component]
let make = (~onClose: unit => unit) => {
  let resetLocalStorage = React.useCallback0(_ => {
    Dom.Storage.clear(Dom.Storage.localStorage);
    Webapi.Dom.location->Webapi.Dom.Location.reloadWithForce;
  });

  <Dialog onClose>
      <Text>helpText</Text>
    <div className=CommonStyles.buttonsArea>
      <button onClick=resetLocalStorage>{React.string("Reset save")}</button>
      <button onClick={_ => onClose()}>{React.string("Close")}</button>
    </div>
  </Dialog>;
};