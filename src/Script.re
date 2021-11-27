type event =
  | Speech(Character.t, string)
  | ExpressionChange(Character.t, Character.expression)
  | Choice(array(choice))
  | GoToScript(list(event))
  | TransitionBackground(Background.t)
  | DrainBattery
and choice = {
  text: string,
  result: list(event),
};
