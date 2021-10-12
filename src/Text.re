module Styles = {
  open Css;

  let text =
      (
        character: option(Character.t),
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
          switch (character) {
          | Some(Yksi) => CommonStyles.yksiHex
          | Some(Kaxig) => CommonStyles.kaxigHex
          | Some(Kolme) => CommonStyles.kolmeHex
          | None => CommonStyles.defaultTextHex
          },
        ),
      ),
    ]);
};

[@react.component]
let make =
    (
      ~character: option(Character.t)=?,
      ~italicize=false,
      ~bold=false,
      ~display=`inline,
      ~children: string,
    ) =>
  <span className={Styles.text(character, italicize, bold, display)}>
    {React.string(children)}
  </span>;
