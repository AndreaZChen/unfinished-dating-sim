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
      | Museum =>
        style([
          backgroundImage(`url("assets/backgrounds/museum.jpg")),
          backgroundSize(`cover),
        ])
      | Arcade =>
        style([
          backgroundImage(`url("assets/backgrounds/deep_fried_arcade.png")),
          backgroundSize(`cover),
        ])
      },
    ]);
  };

  let buttonArea =
    style([
      position(`absolute),
      display(`flex),
      zIndex(CommonStyles.dialogZIndex - 1),
      top(`px(5)),
      left(`px(5)),
    ]);

  let imageDiv =
    style([
      flexGrow(1.),
      position(`relative),
      marginTop(`px(70)),
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

  let choiceItem = (~isHighlighted: bool) =>
    style([
      borderStyle(`solid),
      borderColor(
        `hex(
          isHighlighted
            ? CommonStyles.highlightedChoiceBorderHex
            : CommonStyles.defaultTextHex,
        ),
      ),
      backgroundColor(`hex(CommonStyles.textBoxBackgroundColorHex)),
      width(`percent(100.)),
      media(
        CommonStyles.mediaSizeLarge,
        [borderWidth(`px(isHighlighted ? 6 : 4)), padding(`px(15))],
      ),
      media(
        CommonStyles.mediaSizeMiddle,
        [borderWidth(`px(isHighlighted ? 5 : 3)), padding(`px(10))],
      ),
      media(
        CommonStyles.mediaSizeSmall,
        [borderWidth(`px(isHighlighted ? 4 : 2)), padding(`px(5))],
      ),
      marginRight(`px(10)),
      boxSizing(`borderBox),
    ]);

  let introPlaceholder =
    style([height(`percent(100.)), width(`percent(100.))]);

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

  let hasRecentlyPressedAdvanceKey = React.useRef(false);

  React.useEffect1(
    () => {
      let handler = event => {
        let keyDelay = 150;
        React.Ref.current(hasRecentlyPressedAdvanceKey)
          ? ()
          : (
            switch (Webapi.Dom.KeyboardEvent.code(event)) {
            | "Enter" =>
              Webapi.Dom.KeyboardEvent.preventDefault(event);
              Webapi.Dom.KeyboardEvent.stopPropagation(event);
              globalDispatch(EnterPressed);
              hasRecentlyPressedAdvanceKey->React.Ref.setCurrent(true);
              Js.Global.setTimeout(
                () => {
                  hasRecentlyPressedAdvanceKey->React.Ref.setCurrent(false)
                },
                keyDelay,
              )
              ->ignore;
            | "Space" =>
              Webapi.Dom.KeyboardEvent.preventDefault(event);
              Webapi.Dom.KeyboardEvent.stopPropagation(event);
              globalDispatch(SpacePressed);
              hasRecentlyPressedAdvanceKey->React.Ref.setCurrent(true);
              Js.Global.setTimeout(
                () => {
                  hasRecentlyPressedAdvanceKey->React.Ref.setCurrent(false)
                },
                keyDelay,
              )
              ->ignore;
            | "ArrowUp" =>
              Webapi.Dom.KeyboardEvent.preventDefault(event);
              Webapi.Dom.KeyboardEvent.stopPropagation(event);
              globalDispatch(ArrowUpPressed);
            | "ArrowDown" =>
              Webapi.Dom.KeyboardEvent.preventDefault(event);
              Webapi.Dom.KeyboardEvent.stopPropagation(event);
              globalDispatch(ArrowDownPressed);
            | _ => ()
            }
          );
      };

      Webapi.Dom.EventTarget.addKeyDownEventListener(
        handler,
        Webapi.Dom.window->Webapi.Dom.Window.asEventTarget,
      );

      Some(
        () =>
          Webapi.Dom.EventTarget.removeKeyDownEventListener(
            handler,
            Webapi.Dom.window->Webapi.Dom.Window.asEventTarget,
          ),
      );
    },
    [|globalDispatch|],
  );

  let isDisplayingChoices = Belt.Option.isSome(globalState.displayedChoices);

  <div
    className={Styles.rootWrapper(
      ~backgroundImage=globalState.backgroundImage,
    )}>
    <div className=Styles.buttonArea>
      <HelpButton globalDispatch />
      <MuteButton isSoundMuted={globalState.isSoundMuted} globalDispatch />
    </div>
    <BatteryIndicator isBatteryLow={globalState.isBatteryLow} />
    <ScrollToTopProvider value=scrollToTop>
      {globalState.isIntroDone
         ? <FadeInDiv className=Styles.imageDiv fadeInTime=3000>
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
                  {Belt.Array.mapWithIndex(
                     choices,
                     (index, choice) => {
                       let isHighlighted =
                         switch (globalState.currentHighlightedChoiceIndex) {
                         | Some(highlightedIndex) => index == highlightedIndex
                         | None => false
                         };

                       <FadeInDiv
                         fadeInTime=Styles.fadeInTime
                         key={string_of_int(index)}
                         className={Styles.choiceItem(~isHighlighted)}
                         onClick={_ => globalDispatch(ChoiceSelected(index))}>
                         <Text> {"> " ++ choice.text} </Text>
                       </FadeInDiv>;
                     },
                   )
                   ->React.array}
                </div>
              | None => React.null
              }}
           </FadeInDiv>
         : <div className=Styles.introPlaceholder />}
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
