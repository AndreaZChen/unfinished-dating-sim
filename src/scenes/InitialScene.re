module Scene: Interfaces.Scene = {
  let id = "initialScene";

  let title = {js|🌌 Inside a Machine Void 🌌|js};

  let backgroundColorHex = "141852";

  module Component = {
    [@react.component]
    let make = (~globalDispatch as _: GlobalState.action => unit) => {
      let _scrollToTop = ScrollToTopProvider.useScrollToTop();

      <>
        <FadeInDiv fadeInTime=2000>
          <Text>
            {js|This is some dialogue!

If there were more of it, would be textbox grow to be bigger? Hmm.

Well it certainly doesn't seem that way. But what changed? I must have done something wrong, but I'm not sure what exactly.

Adding more...

And more...

... and more.|js}
          </Text>
        </FadeInDiv>
        <br />
        <FadeInDiv
          className=CommonStyles.buttonsArea
          fadeInTime=2500
          startFadeInAt=2000>
          <button> {React.string("Next")} </button>
        </FadeInDiv>
      </>;
    };
  };

  let renderer = (~globalState as _, ~globalDispatch) =>
    <Component globalDispatch />;
};
