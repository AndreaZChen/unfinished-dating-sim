type action =
  | ScriptAdvanced
  | HelpDialogOpened
  | HelpDialogClosed
  | BackgroundTransitionHalfwayDone(Background.t)
  | BackgroundTransitionDone
  | ChoiceSelected(int)
  | SpacePressed
  | EnterPressed
  | ArrowUpPressed
  | ArrowDownPressed
  | MuteButtonClicked;

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
  currentHighlightedChoiceIndex: option(int),
  isBatteryLow: bool,
  isIntroDone: bool,
  isSoundMuted: bool,
};

let defaultState = {
  script: InitialScript.script,
  isShowingHelpDialog: false,
  backgroundImage: Normal,
  isTransitioningBackground: false,
  isHalfwayDoneTransitioningBackground: false,
  title: "",
  currentSpeakingCharacter: None,
  yksiExpression: Character.Deactivated,
  kaxigExpression: Character.Deactivated,
  kolmeExpression: Character.Deactivated,
  yksiAnimationClass: "",
  kaxigAnimationClass: "",
  kolmeAnimationClass: "",
  text: React.null,
  displayedChoices: None,
  currentHighlightedChoiceIndex: None,
  isBatteryLow: false,
  isIntroDone: false,
  isSoundMuted: false,
};

let textFadeInTime = 1000;

let rec reducer = (action: action, state: t) =>
  switch (action) {
  | ScriptAdvanced =>
    Belt.Option.isSome(state.displayedChoices)
    || state.isTransitioningBackground
      ? ReactUpdate.NoUpdate
      : (
        switch (state.script) {
        | [] =>
          ReactUpdate.SideEffects(
            _self => {
              Webapi.Dom.location->Webapi.Dom.Location.reload;
              None;
            },
          )
        | [nextEvent, ...futureEvents] =>
          let state = {...state, script: futureEvents};
          switch (nextEvent) {
          | Speech(character, text)
          | SpeechAndEndGame(character, text) =>
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
                      <Text character bold=true>
                        {Character.getName(character) ++ ": "}
                      </Text>
                    </FadeInDiv>
                    <FadeInDiv key=text fadeInTime=textFadeInTime>
                      <Text> text </Text>
                    </FadeInDiv>
                  </>,
              },
              self => {
                self.state.isSoundMuted
                  ? ()
                  : (
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
                    }
                  );
                [@warning "-4"]
                (
                  switch (nextEvent) {
                  | SpeechAndEndGame(_) =>
                    Webapi.Dom.location->Webapi.Dom.Location.reload
                  | _ => ()
                  }
                );
                None;
              },
            )
          | Narration(text) =>
            ReactUpdate.Update({
              ...state,
              currentSpeakingCharacter: None,
              yksiAnimationClass: "",
              kaxigAnimationClass: "",
              kolmeAnimationClass: "",
              text:
                <FadeInDiv key=text fadeInTime=textFadeInTime>
                  <Text> text </Text>
                </FadeInDiv>,
            })
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
          | Choice(choices)
          | ChoiceAndEndGame(choices) =>
            ReactUpdate.UpdateWithSideEffects(
              {
                ...state,
                displayedChoices: Some(choices),
                currentHighlightedChoiceIndex: None,
                currentSpeakingCharacter: None,
                yksiAnimationClass: "",
                kaxigAnimationClass: "",
                kolmeAnimationClass: "",
              },
              _self => {
                [@warning "-4"]
                (
                  switch (nextEvent) {
                  | ChoiceAndEndGame(_) =>
                    Webapi.Dom.location->Webapi.Dom.Location.reload
                  | _ => ()
                  }
                );
                None;
              },
            )
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
          | DrainBattery =>
            ReactUpdate.UpdateWithSideEffects(
              {...state, isBatteryLow: true},
              self => {
                self.send(ScriptAdvanced);
                None;
              },
            )
          | CompleteIntro =>
            ReactUpdate.UpdateWithSideEffects(
              {...state, isIntroDone: true},
              self => {
                self.send(ScriptAdvanced);
                None;
              },
            )
          | PlayMuseumMusic =>
            ReactUpdate.UpdateWithSideEffects(
              state,
              self => {
                self.send(ScriptAdvanced);
                Sounds.museumMusic->Sounds.onEnded(_ =>
                  self.send(ScriptAdvanced)
                );
                Sounds.museumMusic->Sounds.play;
                None;
              },
            )
          | StopMuseumMusic =>
            ReactUpdate.UpdateWithSideEffects(
              state,
              self => {
                self.send(ScriptAdvanced);
                Sounds.museumMusic->Sounds.pause;
                None;
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
        {
          ...state,
          displayedChoices: None,
          currentHighlightedChoiceIndex: None,
          script: result,
        },
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
        yksiAnimationClass: "",
        kaxigAnimationClass: "",
        kolmeAnimationClass: "",
        yksiExpression: Neutral,
        kaxigExpression: Neutral,
        kolmeExpression: Neutral,
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
  | ArrowUpPressed =>
    switch (state.displayedChoices) {
    | None => ReactUpdate.NoUpdate
    | Some(choices) =>
      switch (state.currentHighlightedChoiceIndex) {
      | Some(prevIndex) =>
        ReactUpdate.Update({
          ...state,
          currentHighlightedChoiceIndex:
            Some(
              (prevIndex + Belt.Array.length(choices) - 1)
              mod Belt.Array.length(choices),
            ),
        })
      | None =>
        ReactUpdate.Update({
          ...state,
          currentHighlightedChoiceIndex:
            Some(Belt.Array.length(choices) - 1),
        })
      }
    }
  | ArrowDownPressed =>
    switch (state.displayedChoices) {
    | None => ReactUpdate.NoUpdate
    | Some(choices) =>
      switch (state.currentHighlightedChoiceIndex) {
      | Some(prevIndex) =>
        ReactUpdate.Update({
          ...state,
          currentHighlightedChoiceIndex:
            Some((prevIndex + 1) mod Belt.Array.length(choices)),
        })
      | None =>
        ReactUpdate.Update({
          ...state,
          currentHighlightedChoiceIndex: Some(0),
        })
      }
    }
  | SpacePressed =>
    state.isShowingHelpDialog
      ? ReactUpdate.NoUpdate
      : (
        switch (state.displayedChoices, state.currentHighlightedChoiceIndex) {
        | (None, _)
        | (_, None) => reducer(ScriptAdvanced, state)
        | (Some(_choices), Some(highlightedIndex)) =>
          reducer(ChoiceSelected(highlightedIndex), state)
        }
      )
  | EnterPressed =>
    state.isShowingHelpDialog
      ? reducer(HelpDialogClosed, state)
      : (
        switch (state.displayedChoices, state.currentHighlightedChoiceIndex) {
        | (None, _)
        | (_, None) => reducer(ScriptAdvanced, state)
        | (Some(_choices), Some(highlightedIndex)) =>
          reducer(ChoiceSelected(highlightedIndex), state)
        }
      )
  | MuteButtonClicked =>
    ReactUpdate.UpdateWithSideEffects(
      {...state, isSoundMuted: !state.isSoundMuted},
      _self => {
        state.isSoundMuted
          ? Sounds.museumMusic->Sounds.setVolume(Sounds.museumMusicVolume)
          : Sounds.museumMusic->Sounds.setVolume(0.);
        None;
      },
    )
  };
