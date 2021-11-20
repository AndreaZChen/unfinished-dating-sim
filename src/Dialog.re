module Styles = {
  open Css;

  let overlay =
    style([
      zIndex(CommonStyles.dialogZIndex),
      width(`percent(100.)),
      height(`percent(100.)),
      position(`absolute),
      top(`zero),
      left(`zero),
      background(`rgba((0, 0, 0, 0.5))),
      display(`flex),
      alignItems(`center),
      justifyContent(`center),
    ]);

  let content =
    style([
      zIndex(CommonStyles.dialogZIndex + 1),
      maxWidth(`percent(85.)),
      maxHeight(`percent(85.)),
      backgroundColor(`hex(CommonStyles.defaultBackgroundHex)),
      border(`px(4), solid, `hex(CommonStyles.defaultBorderHex)),
      padding(`px(25)),
      whiteSpace(`preWrap),
      boxSizing(`borderBox),
      overflow(`auto),
    ]);
};

[@react.component]
let make = (~onClose: unit => unit, ~children) => {
  let onClose = React.useCallback1(_ => onClose(), [|onClose|]);

  <FadeInDiv fadeInTime=250 className=Styles.overlay onClick=onClose>
    <div className=Styles.content onClick=ReactEvent.Synthetic.stopPropagation>
      children
    </div>
  </FadeInDiv>;
};
