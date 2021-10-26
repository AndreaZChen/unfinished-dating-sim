module Styles = {
  open Css;

  let defaultText = style([
    cursor(`pointer),
    color(`hex(CommonStyles.defaultClickableTextHex)),
    textDecoration(`underline),
    transitionDuration(200),
    display(`inlineBlock),
    hover([
      transform(`scale(1.1, 1.1)),
      color(`hex(CommonStyles.defaultClickableHoveredTextHex)),
    ])
  ]);
}

[@react.component]
let make = (~onClick: unit => unit, ~text: string, ~className=?) => {
  let onClick = React.useCallback1(_ => onClick(), [|onClick|]);
  <span
    role="button"
    className={Belt.Option.getWithDefault(className, Styles.defaultText)}
    onClick>
    {React.string(text)}
  </span>;
};