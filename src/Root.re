module Styles = {
  open Css;

  let rootWrapper = (~backgroundColorHex: option(string)) =>
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
      background(
        `linearGradient((
          `deg(90.),
          [
            (
              `percent(0.),
              `hex(
                Belt.Option.getWithDefault(
                  backgroundColorHex,
                  CommonStyles.defaultBackgroundHex,
                ),
              ),
            ),
            (`percent(5.), `hex(CommonStyles.defaultBackgroundHex)),
            (`percent(95.), `hex(CommonStyles.defaultBackgroundHex)),
            (
              `percent(100.),
              `hex(
                Belt.Option.getWithDefault(
                  backgroundColorHex,
                  CommonStyles.defaultBackgroundHex,
                ),
              ),
            ),
          ],
        )),
      ),
    ]);

  let imageDiv =
    style([
      marginTop(`px(50)),
      display(`grid),
      justifyContent(`center),
      width(`percent(80.)),
      gridTemplateRows([`fr(1.)]),
      gridTemplateColumns([`auto]),
      overflow(`hidden),
      minHeight(`px(200)),
    ]);

  let image =
    style([
      gridRow(1, 2),
      gridColumn(1, 2),
      minWidth(`zero),
      minHeight(`zero),
      maxHeight(`percent(100.)),
      maxWidth(`percent(100.)),
    ]);

  let dialogueArea =
    style([
      flexGrow(1.),
      border(`vmax(0.4), `solid, `hex(CommonStyles.defaultTextHex)),
      padding(`vmax(0.4)),
      overflowX(`hidden),
      overflowY(`auto),
      position(`relative),
      display(`flex),
      flexDirection(`column),
      width(`percent(80.)),
      marginBottom(`px(50)),
      minHeight(`percent(25.)),
      userSelect(`none),
    ]);

  global(
    "body",
    [
      fontFamily("Lato"),
      fontSize(`px(35)),
      media("(max-width: 768px)", [fontSize(`px(17))]),
      lineHeight(`abs(1.8)),
      backgroundColor(`hex(CommonStyles.defaultBackgroundHex)),
    ],
  );
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

  <div
    className={Styles.rootWrapper(
      ~backgroundColorHex=globalState.backgroundColorHex,
    )}>
    <HelpButton globalDispatch />
    <ScrollToTopProvider value=scrollToTop>
      <div className=Styles.imageDiv>
        <img className=Styles.image src="../assets/characters/body.png" />
        <img
          className=Styles.image
          src={Character.getImage(Yksi, globalState.yksiExpression)}
        />
        <img
          className=Styles.image
          src={Character.getImage(Kaxig, globalState.kaxigExpression)}
        />
        <img
          className=Styles.image
          src={Character.getImage(Kolme, globalState.kolmeExpression)}
        />
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
  </div>;
};
