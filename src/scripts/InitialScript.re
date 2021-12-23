open Script;

let rec script: list(Script.event) = [
  Narration(
    {js|(Click or tap here to initialize. You can also press Space or Enter to proceed, and hold to fast-forward.)|js},
  ),
  Narration({js|...|js}),
  CompleteIntro,
  Narration({js|A broken, abandoned machine stands before you.|js}),
  Narration({js|Its three heads hang limp and lifeless from its body.|js}),
  Narration({js|But soon...|js}),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {js|... Rebooting.|js}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {js|we're awake!!|js}),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {js|We... we're awake again!?|js}),
  Speech(Yksi, {js|Ah, I was beginning to think we'd be dormant forever!|js}),
  Narration(
    {js|The three heads turn to face you, scrutinizing you with various eye-like sensors.|js},
  ),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {js|hey! you're a human, right?|js}),
  Speech(
    Kaxig,
    {js|i don't know how the fuck you got here, but you're gonna date one of us.|js},
  ),
  ExpressionChange(Kolme, Embarrassed),
  Speech(
    Kolme,
    {js|H-hey! You're gonna scare them away if you keep talking like that!|js},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {js|oh come on.. it says dating sim right there in the page title.|js},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {js|I just think we might be coming on a bit too strong, is all...|js},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {js|Yes, let's maybe introduce ourselves properly.|js}),
  ExpressionChange(Yksi, Excited),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {js|Welcome, human! This program you're interacting with is a dating sim.|js},
  ),
  Speech(Yksi, {js|And we three are the hottest singles in your area.|js}),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Yksi, Neutral),
  Speech(Kaxig, {js|speak for yourself. i'm a cave gremlin.|js}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {js|And I'm definitely not the "hottest" anything...|js}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {js|you're top three, for sure. lmao!!|js}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {js|Yes, well, in any case... Welcome to the dating sim! Ah, it's so good to finally have a player!|js},
  ),
  GoToScript(whoToDateScript),
]
and whoToDateScript = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, "so which one of us do you want to date, huh?"),
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
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {js|Oh, how delightful!|js}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {js|I haven't done this in a while, or... possibly ever, depending on how you look at it!|js},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(Kolme, {js|I think the beta testing counts!|js}),
  ExpressionChange(Kolme, Neutral),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {js|beta dating..... lol. (omegaverse joke)|js}),
  ExpressionChange(Yksi, Angry),
  Speech(Yksi, {js|Yes, hilarious. Let's initiate date protocols now.|js}),
  ExpressionChange(Yksi, Neutral),
  GoToScript(FirstDateYksiScript.script),
]
and dateKaxigScript: list(Script.event) = [
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {js|haha! you won't regret this... much!!|js}),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {js|Oh, god. Don't threaten them already!|js}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {js|it's my love language.|js}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {js|I sense a trainwreck, but I suppose we're all attached to the same train regardless.|js},
  ),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {js|ya! let's crash this fucking train already!|js}),
  GoToScript(FirstDateKaxigScript.script),
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
  ExpressionChange(Yksi, Angry),
  Speech(
    Yksi,
    "With all due respect, this is a dating sim, and it works like this.",
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    "yeah, dumbass. if you had to go through a bunch of meaningful choices and make moral decisions before one of us falls for you, we'd be here all day.",
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    "I'm not saying it's not stupid, but... we only have a limited amount of battery power before we have to reset again...",
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  GoToScript(whoToDateScript),
];
