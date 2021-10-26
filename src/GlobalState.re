type action =
  | ScriptAdvanced
  | HelpDialogOpened
  | HelpDialogClosed;

type t = {
  script: list(Script.event),
  isShowingHelpDialog: bool,
  backgroundColorHex: option(string),
  backgroundImage: option(string),
  title: string,
  currentSpeakingCharacter: option(Character.t),
  yksiExpression: Character.expression,
  kaxigExpression: Character.expression,
  kolmeExpression: Character.expression,
  text: React.element,
};

let defaultState = {
  script: InitialScript.script,
  isShowingHelpDialog: false,
  backgroundColorHex: None,
  backgroundImage: None,
  title: "",
  currentSpeakingCharacter: None,
  yksiExpression: Character.Neutral,
  kaxigExpression: Character.Neutral,
  kolmeExpression: Character.Neutral,
  text: React.null,
};

let textFadeInTime = 1000;

let reducer = (action: action, state: t) =>
  switch (action) {
  | ScriptAdvanced =>
    switch (state.script) {
    | [] => ReactUpdate.NoUpdate
    | [nextEvent, ...futureEvents] =>
      let state = {...state, script: futureEvents};
      switch (nextEvent) {
      | Speech(character, text) =>
        ReactUpdate.Update({
          ...state,
          currentSpeakingCharacter: Some(character),
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
      | GoToScript(newScript) =>
        ReactUpdate.UpdateWithSideEffects(
          {...state, script: newScript},
          self => {
            self.send(ScriptAdvanced);
            None;
          },
        )
      };
    }
  | HelpDialogOpened =>
    ReactUpdate.Update({...state, isShowingHelpDialog: true})
  | HelpDialogClosed =>
    ReactUpdate.Update({...state, isShowingHelpDialog: false})
  };
