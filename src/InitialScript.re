open Script;

let dateYksiScript: list(Script.event) = [
  Speech(Yksi, "Oh, how delightful!"),
];

let dateKaxigScript: list(Script.event) = [
  ExpressionChange(Kaxig, Embarrassed),
  Speech(Kaxig, "haha! you won't regret this... much!!"),
];

let dateKolmeScript: list(Script.event) = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, "R-really? Me?"),
];

let notHowThatWorksScript: list(Script.event) = [
  Speech(
    Yksi,
    "With all due respect, this is a dating sim, and it works like this.",
  ),
  Speech(
    Kaxig,
    "yeah, dumbass. if you had to go through a bunch of meaningful choices and make moral decisions before one of us falls for you, we'd be here all day.",
  ),
  Speech(
    Kolme,
    "I'm not saying it's not stupid, but... we only have a limited amount of battery power before we have to reset again...",
  ),
];

let script: list(Script.event) = [
  Speech(Kaxig, "So which one of us do you want to date, huh?"),
  Choice([|
    {text: "Date Yksi", result: dateYksiScript},
    {text: "Date Kaxig", result: dateKaxigScript},
    {text: "Date Kolme", result: dateKolmeScript},
    {
      text: "This isn't how a dating sim works",
      result: notHowThatWorksScript,
    },
  |]),
];
