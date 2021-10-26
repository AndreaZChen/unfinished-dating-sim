open Script;

let rec script: list(Script.event) = [
  Speech(Kolme, "Hello!"),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, "Oh, I'm embarrassed now!"),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, "But now I'm fine again."),
  GoToScript(script),
];
