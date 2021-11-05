open Script;

let rec script: list(Script.event) = [
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
]
and dateYksiScript: list(Script.event) = [
  Speech(Yksi, "Oh, how delightful!"),
]
and dateKaxigScript: list(Script.event) = [
  ExpressionChange(Kaxig, Embarrassed),
  Speech(Kaxig, "haha! you won't regret this... much!!"),
]
and dateKolmeScript: list(Script.event) = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, "R-really? Me?"),
  Speech(
    Kolme,
    "I'm not sure why you would pick me, but... I'm glad you're willing to give it a try...!",
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    "Well... let's get to know each other a little better, then...",
  ),
  ExpressionChange(Kolme, Embarrassed),
  Speech(
    Kolme,
    "Other selves, d-do you mind giving us some privacy? I think this is supposed to be intimate.",
  ),
  Speech(Yksi, "I would love to, but I'm actually attached to our body."),
  Speech(Kaxig, "i wanna watch."),
  Speech(Kolme, "Well, I... okay...!"),
  GoToScript(FirstDateKolmeScript.script),
]
and notHowThatWorksScript: list(Script.event) = [
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