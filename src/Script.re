type event =
  | Speech(Character.t, string)
  | SpeechAndEndGame(Character.t, string)
  | Narration(string)
  | ExpressionChange(Character.t, Character.expression)
  | Choice(array(choice))
  | ChoiceAndEndGame(array(choice))
  | GoToScript(list(event))
  | TransitionBackground(Background.t)
  | DrainBattery
  | CompleteIntro
and choice = {
  text: string,
  result: list(event),
};
