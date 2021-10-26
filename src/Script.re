type event =
  | Speech(Character.t, string)
  | ExpressionChange(Character.t, Character.expression)
  | GoToScript(list(event));
