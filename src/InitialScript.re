open Script;

let rec dateYksiScript: list(Script.event) = [
  Speech(Yksi, "Oh, how delightful!"),
  GoToScript(script),
]
and dateKolmeScript: list(Script.event) = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, "R-really? Me?"),
  GoToScript(script),
]
and script: list(Script.event) = [
  Speech(Kaxig, "So which one of us do you want to date, huh?"),
  Choice([|
    {text: "Date Yksi", result: dateYksiScript},
    {text: "Date Kolme", result: dateKolmeScript},
  |]),
];
