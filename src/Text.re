module Styles = {
  open Css;

  let text =
      (
        character: option(Character.t),
        customColorHex: option(string),
        italicize: bool,
        bold: bool,
        displayValue,
      ) =>
    style([
      whiteSpace(`preWrap),
      fontStyle(italicize ? `italic : `normal),
      fontWeight(bold ? `bold : `normal),
      display(displayValue),
      color(
        `hex(
          Belt.Option.getWithDefault(
            customColorHex,
            switch (character) {
            | Some(Yksi) => CommonStyles.yksiHex
            | Some(Kaxig) => CommonStyles.kaxigHex
            | Some(Kolme) => CommonStyles.kolmeHex
            | None => CommonStyles.defaultTextHex
            },
          ),
        ),
      ),
    ]);
};

[@react.component]
let make =
    (
      ~character: option(Character.t)=?,
      ~customColorHex: option(string)=?,
      ~italicize=false,
      ~bold=false,
      ~display=`inline,
      ~children: string,
    ) =>
  <span
    className={Styles.text(
      character,
      customColorHex,
      italicize,
      bold,
      display,
    )}>
    {React.string(children)}
  </span>;
