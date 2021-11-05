type action =
  | ScriptAdvanced
  | HelpDialogOpened
  | HelpDialogClosed
  | BackgroundTransitionHalfwayDone(Background.t)
  | BackgroundTransitionDone
  | ChoiceSelected(int);

type t = {
  script: list(Script.event),
  isShowingHelpDialog: bool,
  backgroundImage: Background.t,
  isTransitioningBackground: bool,
  isHalfwayDoneTransitioningBackground: bool,
  title: string,
  currentSpeakingCharacter: option(Character.t),
  yksiExpression: Character.expression,
  kaxigExpression: Character.expression,
  kolmeExpression: Character.expression,
  yksiAnimationClass: string,
  kaxigAnimationClass: string,
  kolmeAnimationClass: string,
  text: React.element,
  displayedChoices: option(array(Script.choice)),
};

let defaultState = {
  script: InitialScript.script,
  isShowingHelpDialog: false,
  backgroundImage: Normal,
  isTransitioningBackground: false,
  isHalfwayDoneTransitioningBackground: false,
  title: "",
  currentSpeakingCharacter: None,
  yksiExpression: Character.Neutral,
  kaxigExpression: Character.Neutral,
  kolmeExpression: Character.Neutral,
  yksiAnimationClass: "",
  kaxigAnimationClass: "",
  kolmeAnimationClass: "",
  text: React.null,
  displayedChoices: None,
};

let textFadeInTime = 1000;

let reducer = (action: action, state: t) =>
  switch (action) {
  | ScriptAdvanced =>
    Belt.Option.isSome(state.displayedChoices)
    || state.isTransitioningBackground
      ? ReactUpdate.NoUpdate
      : (
        switch (state.script) {
        | [] =>
          ReactUpdate.UpdateWithSideEffects(
            defaultState,
            self => {
              self.send(ScriptAdvanced);
              None;
            },
          )
        | [nextEvent, ...futureEvents] =>
          let state = {...state, script: futureEvents};
          switch (nextEvent) {
          | Speech(character, text) =>
            ReactUpdate.UpdateWithSideEffects(
              {
                ...state,
                currentSpeakingCharacter: Some(character),
                yksiAnimationClass: character == Yksi ? "shakeX" : "",
                kaxigAnimationClass: character == Kaxig ? "rubberBand" : "",
                kolmeAnimationClass: character == Kolme ? "headShake" : "",
                text:
                  <>
                    <FadeInDiv
                      fadeInTime={
                        switch (state.currentSpeakingCharacter) {
                        | Some(currentCharacter) =>
                          currentCharacter == character ? 0 : textFadeInTime
                        | None => textFadeInTime
                        }
                      }>
                      <Text character>
                        {Character.getName(character) ++ ": "}
                      </Text>
                    </FadeInDiv>
                    <FadeInDiv key=text fadeInTime=textFadeInTime>
                      <Text> text </Text>
                    </FadeInDiv>
                  </>,
              },
              _self => {
                switch (character, state.currentSpeakingCharacter) {
                | (Yksi, Some(Kaxig) | Some(Kolme) | None) =>
                  Sounds.yksiNoise1->Sounds.play
                | (Kaxig, Some(Yksi) | Some(Kolme) | None) =>
                  Sounds.kaxigNoise1->Sounds.play
                | (Kolme, Some(Yksi) | Some(Kaxig) | None) =>
                  Sounds.kolmeNoise1->Sounds.play
                | (Yksi, Some(Yksi)) => ()
                | (Kaxig, Some(Kaxig)) => ()
                | (Kolme, Some(Kolme)) => ()
                };
                None;
              },
            )
          | ExpressionChange(character, expression) =>
            ReactUpdate.UpdateWithSideEffects(
              switch (character) {
              | Yksi => {...state, yksiExpression: expression}
              | Kaxig => {...state, kaxigExpression: expression}
              | Kolme => {...state, kolmeExpression: expression}
              },
              self => {
                self.send(ScriptAdvanced);
                None;
              },
            )
          | Choice(choices) =>
            ReactUpdate.Update({
              ...state,
              displayedChoices: Some(choices),
              yksiAnimationClass: "",
              kaxigAnimationClass: "",
              kolmeAnimationClass: "",
            })
          | GoToScript(newScript) =>
            ReactUpdate.UpdateWithSideEffects(
              {...state, script: newScript},
              self => {
                self.send(ScriptAdvanced);
                None;
              },
            )
          | TransitionBackground(backgroundImage) =>
            ReactUpdate.UpdateWithSideEffects(
              {
                ...state,
                isTransitioningBackground: true,
                isHalfwayDoneTransitioningBackground: false,
              },
              self => {
                let timerId =
                  Js.Global.setTimeout(
                    () =>
                      self.send(
                        BackgroundTransitionHalfwayDone(backgroundImage),
                      ),
                    CommonStyles.overlayTransitionMs,
                  );
                Some(() => Js.Global.clearTimeout(timerId));
              },
            )
          };
        }
      )
  | ChoiceSelected(index) =>
    let selectedChoice =
      Belt.Option.flatMap(state.displayedChoices, choices =>
        Belt.Array.get(choices, index)
      );

    switch (selectedChoice) {
    | Some({result, _}) =>
      ReactUpdate.UpdateWithSideEffects(
        {...state, displayedChoices: None, script: result},
        self => {
          self.send(ScriptAdvanced);
          None;
        },
      )
    | None => ReactUpdate.NoUpdate
    };
  | BackgroundTransitionHalfwayDone(backgroundImage) =>
    ReactUpdate.UpdateWithSideEffects(
      {
        ...state,
        currentSpeakingCharacter: None,
        text: React.null,
        backgroundImage,
        isHalfwayDoneTransitioningBackground: true,
      },
      self => {
        let timerId =
          Js.Global.setTimeout(
            () => self.send(BackgroundTransitionDone),
            CommonStyles.overlayTransitionMs,
          );
        Some(() => Js.Global.clearTimeout(timerId));
      },
    )
  | BackgroundTransitionDone =>
    ReactUpdate.UpdateWithSideEffects(
      {
        ...state,
        isTransitioningBackground: false,
        isHalfwayDoneTransitioningBackground: false,
      },
      self => {
        self.send(ScriptAdvanced);
        None;
      },
    )
  | HelpDialogOpened =>
    ReactUpdate.Update({...state, isShowingHelpDialog: true})
  | HelpDialogClosed =>
    ReactUpdate.Update({...state, isShowingHelpDialog: false})
  };
