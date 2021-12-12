open Script;

let rec script: list(Script.event) = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Excited),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, {j|i'm about to take you somewhere fucked up. let's go!|j}),
  TransitionBackground(Arcade),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Excited),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, {j|this is a deep-fried arcade!!|j}),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|Wh...!? Help!?|j}),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|A bit garish for a first date, perhaps...|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(
    Kaxig,
    {j|nah bud. dating is all about being noisy and grainy and washed-out like hell.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, {j|so, player. whatcha think?|j}),
  Choice([|
    {text: "It's lovely", result: loveItScript},
    {text: "I hate it here", result: hateItScript},
  |]),
]
and loveItScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|what!? ah, dangit. i was hoping you'd think it sucked ass.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|yeah, well. there'll be more opportunities for ass-sucking later. let's just keep going.|j},
  ),
  GoToScript(script),
]
and hateItScript = [
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|yes... ha ha ha... YES!|j}),
  Speech(
    Kaxig,
    {j|see, now you already kinda hate this date a little. and that's good, see?|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|these other two chumps think you're supposed to start out being nice to each other, lmao.|j},
  ),
  Speech(
    Kaxig,
    {j|nah, i'm on that next-level shit. ENEMIES TO LOVERS, that's how we do dating.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|That's fair, actually. The only trope better than enemies to lovers is lovers to enemies.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|we'll do that one afterwards if there's time. anyway...|j},
  ),
  GoToScript(script),
];
