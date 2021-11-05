open Script;

let rec script: list(Script.event) = [
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, "Um... let's start by going to an appropriate dating venue."),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    "Unfortunately, we only have access to a limited number of graphical assets.",
  ),
  Speech(
    Kolme,
    "I'd like to take you somewhere nice for our first date, but... let's see what we've got...",
  ),
  TransitionBackground(CyberCafe),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Um... welcome to the Cyber Café.|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|...|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Well, let's start dating! I'll ask you some questions so you can tell me more about yourself!|j},
  ),
  Speech(
    Kolme,
    {j|What's, uh, what's your favorite type of control statement?|j},
  ),
  Choice([|
    {text: "if statement", result: ifStatementScript},
    {text: "for loop", result: forLoopScript},
    {text: "while loop", result: whileLoopScript},
    {text: "switch", result: switchScript},
    {text: "Telling someone to fuck off", result: fuckOffScript},
  |]),
]
and ifStatementScript = [
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|That's a really good control statement! The ternary operator makes it so convenient too!|j},
  ),
  GoToScript(script),
]
and forLoopScript = [
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Yeah, those are neat! Iterating over things... it's very pleasing and organized.|j},
  ),
  GoToScript(script),
]
and whileLoopScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Heh... yeah... while loops...|j}),
  Speech(
    Kolme,
    {j|Repeating the same snippet of code over and over, maybe just a few times or maybe very many...|j},
  ),
  Speech(
    Kolme,
    {j|Without a proper break condition, you could get stuck just doing the same things again and again, forever...|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|Yeah...|j}),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|yeah.|j}),
  Speech(Kolme, {j|...|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Um... but I'm glad you like them, anyway, hehe.|j}),
  GoToScript(script),
]
and switchScript = [
  ExpressionChange(Kolme, Excited),
  Speech(Kolme, {j|Aha, so you're into switches!|j}),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|... W-wait!! I don't mean it like that!|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|lol. lmao.|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|This is already going terribly... augh...|j}),
  GoToScript(script),
]
and fuckOffScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Oh, god. Y-you're so... direct...!?|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I... hope you're not going to say that to me, ehe... at least not yet...|j},
  ),
  GoToScript(script),
];
