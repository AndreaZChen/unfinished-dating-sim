module Styles = {
  open Css;

  let fadeInTime = 1000;

  let rootWrapper = (~backgroundImage as bg: Background.t) => {
    let baseStyle =
      style([
        overflow(`hidden),
        position(`absolute),
        display(`flex),
        alignItems(`center),
        justifyContent(`flexStart),
        flexDirection(`column),
        width(`percent(100.)),
        height(`percent(100.)),
        bottom(`px(0)),
        right(`px(0)),
        transitionDuration(500),
      ]);

    merge([
      baseStyle,
      switch (bg) {
      | Normal =>
        style([backgroundColor(`hex(CommonStyles.defaultBackgroundHex))])
      | CyberCafe =>
        style([
          backgroundImage(`url("assets/backgrounds/cafe.jpeg")),
          backgroundSize(`cover),
        ])
      },
    ]);
  };

  let imageDiv =
    style([
      flexGrow(1.),
      position(`relative),
      marginTop(`px(50)),
      display(`grid),
      alignItems(`end_),
      width(`percent(80.)),
      gridTemplateRows([`fr(1.)]),
      gridTemplateColumns([`auto]),
      overflow(`hidden),
      userSelect(`none),
    ]);

  let image = (~isFaded: bool) =>
    style([
      opacity(isFaded ? 0.2 : 1.),
      transition(~duration=fadeInTime, "opacity"),
      gridRow(1, 2),
      gridColumn(1, 2),
      justifySelf(`center),
      minWidth(`zero),
      minHeight(`zero),
      maxHeight(`percent(100.)),
      maxWidth(`percent(100.)),
    ]);

  let dialogueArea =
    style([
      borderColor(`hex(CommonStyles.defaultTextHex)),
      borderStyle(`solid),
      backgroundColor(`hex(CommonStyles.textBoxBackgroundColorHex)),
      media(
        CommonStyles.mediaSizeLarge,
        [borderWidth(`px(4)), padding(`px(30))],
      ),
      media(
        CommonStyles.mediaSizeMiddle,
        [borderWidth(`px(3)), padding(`px(20))],
      ),
      media(
        CommonStyles.mediaSizeSmall,
        [borderWidth(`px(2)), padding(`px(10))],
      ),
      overflowX(`hidden),
      overflowY(`auto),
      position(`relative),
      display(`flex),
      flexDirection(`column),
      width(`percent(80.)),
      marginBottom(`px(50)),
      minHeight(`percent(30.)),
      height(`percent(30.)),
      maxHeight(`percent(30.)),
      userSelect(`none),
      boxSizing(`borderBox),
    ]);

  let choicesDiv =
    style([
      position(`absolute),
      height(`percent(100.)),
      width(`auto),
      display(`flex),
      media(CommonStyles.mediaSizeLarge, [flexWrap(`wrap)]),
      media(CommonStyles.mediaSizeMiddle, [flexWrap(`nowrap)]),
      media(CommonStyles.mediaSizeSmall, [flexWrap(`nowrap)]),
      overflowY(`auto),
      overflowX(`hidden),
      flexDirection(`column),
      justifyContent(`spaceEvenly),
      alignItems(`flexStart),
      boxSizing(`borderBox),
    ]);

  let choiceItem =
    style([
      border(`vmax(0.4), `solid, `hex(CommonStyles.defaultTextHex)),
      backgroundColor(`hex(CommonStyles.textBoxBackgroundColorHex)),
      width(`percent(100.)),
      media(
        CommonStyles.mediaSizeLarge,
        [borderWidth(`px(4)), padding(`px(15))],
      ),
      media(
        CommonStyles.mediaSizeMiddle,
        [borderWidth(`px(3)), padding(`px(10))],
      ),
      media(
        CommonStyles.mediaSizeSmall,
        [borderWidth(`px(2)), padding(`px(5))],
      ),
      marginRight(`px(10)),
      boxSizing(`borderBox),
    ]);

  global(
    "body",
    [
      fontFamily("Courier"),
      media(CommonStyles.mediaSizeLarge, [fontSize(`px(35))]),
      media(CommonStyles.mediaSizeMiddle, [fontSize(`px(24))]),
      media(CommonStyles.mediaSizeSmall, [fontSize(`px(17))]),
      lineHeight(`abs(1.0)),
      backgroundColor(`hex(CommonStyles.defaultBackgroundHex)),
    ],
  );
};

module CharacterImage = {
  [@react.component]
  let make = (~src: string, ~isFaded: bool, ~animationClass: string) =>
    <img
      className={
        Styles.image(~isFaded)
        ++ " animate__animated animate__"
        ++ animationClass
      }
      src
    />;
};

module BatteryIndicator = {
  module Styles = {
    open Css;

    let image =
      style([
        position(`absolute),
        zIndex(CommonStyles.dialogZIndex - 1),
        top(`px(5)),
        right(`px(5)),
        userSelect(`none),
        margin(`px(10)),
        media(CommonStyles.mediaSizeLarge, [width(`px(100))]),
        media(CommonStyles.mediaSizeMiddle, [width(`px(75))]),
        media(CommonStyles.mediaSizeSmall, [width(`px(50))]),
        animationIterationCount(`count(10)),
      ]);
  };

  [@react.component]
  let make = (~isBatteryLow: bool) =>
    <img
      className={
        Styles.image
        ++ (isBatteryLow ? " animate__animated animate__flash" : "")
      }
      src={
        isBatteryLow
          ? "assets/characters/battery_low.png"
          : "assets/characters/battery_full.png"
      }
    />;
};

module BlackOverlay = {
  module Styles = {
    open Css;

    let fadeIn =
      keyframes([
        (0, [opacity(0.)]),
        (50, [opacity(1.)]),
        (100, [opacity(1.)]),
      ]);

    let fadeOut =
      keyframes([
        (0, [opacity(1.)]),
        (50, [opacity(0.)]),
        (100, [opacity(0.)]),
      ]);

    let overlay = (~isHalfwayDone: bool) =>
      style([
        backgroundColor(`hex("000000")),
        opacity(isHalfwayDone ? 1. : 0.),
        animationName(isHalfwayDone ? fadeOut : fadeIn),
        animationDuration(CommonStyles.overlayTransitionMs * 2),
        zIndex(CommonStyles.overlayZIndex),
        width(`percent(100.)),
        height(`percent(100.)),
        position(`fixed),
        top(`zero),
        left(`zero),
      ]);
  };

  [@react.component]
  let make = (~isHalfwayDone: bool) => {
    <div className={Styles.overlay(~isHalfwayDone)} />;
  };
};

[@react.component]
let make = () => {
  let (globalState, globalDispatch) =
    ReactUpdate.useReducer(GlobalState.defaultState, GlobalState.reducer);

  let centralColumnRef = React.useRef(Js.Nullable.null);

  React.useEffect0(() => {
    globalDispatch(ScriptAdvanced);
    None;
  });

  let scrollToTop =
    React.useCallback1(
      () =>
        centralColumnRef
        ->React.Ref.current
        ->Js.Nullable.toOption
        ->Belt.Option.mapWithDefault((), element =>
            Webapi.Dom.Element.setScrollTop(element, 0.)
          ),
      [|centralColumnRef|],
    );

  let onCloseHelpDialog =
    React.useCallback1(
      () => globalDispatch(HelpDialogClosed),
      [|globalDispatch|],
    );

  let onDialogueClicked =
    React.useCallback1(
      _ => globalDispatch(ScriptAdvanced),
      [|globalDispatch|],
    );

  let isDisplayingChoices = Belt.Option.isSome(globalState.displayedChoices);

  <div
    className={Styles.rootWrapper(
      ~backgroundImage=globalState.backgroundImage,
    )}>
    <HelpButton globalDispatch />
    <BatteryIndicator isBatteryLow={globalState.isBatteryLow} />
    <ScrollToTopProvider value=scrollToTop>
      <div className=Styles.imageDiv>
        <CharacterImage
          isFaded=isDisplayingChoices
          animationClass={globalState.yksiAnimationClass}
          src={Character.getImage(Yksi, globalState.yksiExpression)}
        />
        <CharacterImage
          isFaded=isDisplayingChoices
          animationClass={globalState.kaxigAnimationClass}
          src={Character.getImage(Kaxig, globalState.kaxigExpression)}
        />
        <CharacterImage
          isFaded=isDisplayingChoices
          animationClass={globalState.kolmeAnimationClass}
          src={Character.getImage(Kolme, globalState.kolmeExpression)}
        />
        <CharacterImage
          isFaded=isDisplayingChoices
          animationClass=""
          src="assets/characters/body.png"
        />
        {switch (globalState.displayedChoices) {
         | Some(choices) =>
           <div className=Styles.choicesDiv>
             {Belt.Array.mapWithIndex(choices, (index, choice) =>
                <FadeInDiv
                  fadeInTime=Styles.fadeInTime
                  key={string_of_int(index)}
                  className=Styles.choiceItem
                  onClick={_ => globalDispatch(ChoiceSelected(index))}>
                  <Text> {"> " ++ choice.text} </Text>
                </FadeInDiv>
              )
              ->React.array}
           </div>
         | None => React.null
         }}
      </div>
      <div
        role="button"
        className=Styles.dialogueArea
        onClick=onDialogueClicked
        ref={ReactDOMRe.Ref.domRef(centralColumnRef)}>
        {globalState.text}
      </div>
    </ScrollToTopProvider>
    {globalState.isShowingHelpDialog
       ? <HelpDialog onClose=onCloseHelpDialog /> : React.null}
    {globalState.isTransitioningBackground
       ? <BlackOverlay
           isHalfwayDone={globalState.isHalfwayDoneTransitioningBackground}
         />
       : React.null}
  </div>;
};
