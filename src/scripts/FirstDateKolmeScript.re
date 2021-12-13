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
    "I'd like to take you somewhere nice for our first date, so... let's see what we've got in these files...",
  ),
  TransitionBackground(CyberCafe),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Um... welcome to the Cyber Café.|j}),
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|Ah, the Cyber Café! You've selected an excellent venue for romance, my other self! A classic.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|It's quite compressed, though.|j}),
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
  GoToScript(secondQuestionScript),
]
and forLoopScript = [
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Yeah, those are neat! Iterating over things... it's very pleasing and organized.|j},
  ),
  GoToScript(secondQuestionScript),
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
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Um... but I'm glad you like them, anyway, hehe.|j}),
  GoToScript(secondQuestionScript),
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
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Or, depending on how you look at it, extremely well!|j}),
  ExpressionChange(Yksi, Neutral),
  GoToScript(secondQuestionScript),
]
and fuckOffScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Oh, god. Y-you're so... direct...!?|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I... hope you're not going to say that to me, ehe... at least not yet...|j},
  ),
  GoToScript(secondQuestionScript),
]
and secondQuestionScript = [
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Well, so... normally I guess we'd have coffee or something... but this is only a stock photo of a café.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|We don't have much to offer around here.|j}),
  Speech(Kaxig, {j|you're really selling them on this, huh?|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|...|j}),
  Speech(
    Kolme,
    {j|Um... I can ask more questions about you if you'd like.|j},
  ),
  Choice([|
    {text: "Yes please", result: KolmeMoreQuestionsScript.script},
    {
      text: "I want to know more about you",
      result: AskAboutKolmeScript.script,
    },
  |]),
];
