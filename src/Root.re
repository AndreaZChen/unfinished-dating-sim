module Styles = {
  open Css;

  let rootWrapper = (~backgroundColorHex) =>
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
            (`percent(0.), `hex(backgroundColorHex)),
            (`percent(5.), `hex(CommonStyles.defaultBackgroundHex)),
            (`percent(95.), `hex(CommonStyles.defaultBackgroundHex)),
            (`percent(100.), `hex(backgroundColorHex)),
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
      overflowX(`hidden),
      overflowY(`auto),
      position(`relative),
      display(`flex),
      flexDirection(`column),
      width(`percent(80.)),
      maxHeight(`percent(50.)),
      minHeight(`px(200)),
    ]);

  global(
    "body",
    [
      fontFamily("Lato"),
      lineHeight(`abs(1.8)),
      backgroundColor(`hex(CommonStyles.defaultBackgroundHex)),
    ],
  );
};

let getInitialState: unit => GlobalState.t =
  () =>
    GlobalState.loadState()
    ->Belt.Option.getWithDefault({
        ...GlobalState.defaultState,
        currentSceneId: InitialScene.Scene.id,
      });

[@react.component]
let make = () => {
  let (globalState, globalDispatch) =
    ReactUpdate.useReducer(getInitialState(), GlobalState.reducer);

  let centralColumnRef = React.useRef(Js.Nullable.null);

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

  let (module CurrentScene): (module Interfaces.Scene) =
    React.useMemo1(
      () => SceneUtils.getSceneById(globalState.currentSceneId),
      [|globalState.currentSceneId|],
    );

  <div
    className={Styles.rootWrapper(
      ~backgroundColorHex=CurrentScene.backgroundColorHex,
    )}>
    <HelpButton globalDispatch />
    <ScrollToTopProvider value=scrollToTop>
      <div className=Styles.imageDiv>
        <img className=Styles.image src="../assets/characters/body.png" />
        <img
          className=Styles.image
          src="../assets/characters/yksi_neutral.png"
        />
        <img
          className=Styles.image
          src="../assets/characters/kaxig_neutral.png"
        />
        <img
          className=Styles.image
          src="../assets/characters/kolme_neutral.png"
        />
      </div>
      <div
        className=Styles.dialogueArea
        ref={ReactDOMRe.Ref.domRef(centralColumnRef)}>
        {CurrentScene.renderer(~globalState, ~globalDispatch)}
      </div>
    </ScrollToTopProvider>
    {globalState.isShowingHelpDialog
       ? <HelpDialog onClose=onCloseHelpDialog /> : React.null}
  </div>;
};
