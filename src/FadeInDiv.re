module Styles = {
  open Css;

  let fadeIn = startFadeInAtPercent =>
    keyframes([
      (0, [opacity(0.)]),
      (startFadeInAtPercent, [opacity(0.)]),
      (100, [opacity(1.)]),
    ]);

  let wrapper = (fadeInTime, startFadeInAtPercent) =>
    style([
      animationName(fadeIn(startFadeInAtPercent)),
      animationDuration(fadeInTime),
    ]);
};

[@react.component]
let make =
    (
      ~children: React.element,
      ~className=?,
      ~fadeInTime=1000,
      ~startFadeInAt=0,
      ~onClick=?,
    ) => {
  let startFadeInAtPercent =
    startFadeInAt == 0
    ? 0
    : ((float_of_int(startFadeInAt) /. float_of_int(fadeInTime)) *. 100.)
      ->max(0.)
      ->min(100.)
      ->int_of_float;

  let fadeInClassName = Styles.wrapper(fadeInTime, startFadeInAtPercent);
  let className = Belt.Option.mapWithDefault(className, fadeInClassName, someClass => Css.merge([someClass, fadeInClassName]));
  <div className ?onClick> children </div>;
};