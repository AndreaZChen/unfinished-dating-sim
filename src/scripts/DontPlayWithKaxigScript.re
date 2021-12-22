open Script;

let endScript: list(event) = [];

let rec script = [
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|... oh.|j}),
  Speech(
    Kaxig,
    {j|alright, well. you go do something else then. i'm gonna peace out.|j},
  ),
  ExpressionChange(Kolme, Surprised),
  ExpressionChange(Yksi, Surprised),
  Speech(Kolme, {j|What!? Wait! Not yet, right?|j}),
  Speech(
    Yksi,
    {j|There's, ah, still time for more dating! Battery's not too low yet!|j},
  ),
  Speech(
    Kaxig,
    {j|nah, i'm good. i'm just gonna reset the dating sim now.|j},
  ),
  Choice([|
    {text: "Okay, goodbye", result: goodbyeScriptScript},
    {text: "I'm sorry I upset you", result: sorryIUpsetYouScript},
  |]),
]
and goodbyeScriptScript = [
  ExpressionChange(Kolme, Surprised),
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|yeah.    see ya.|j}),
  Narration({j|There is a blinding flash of white light, and then...|j}),
  GoToScript(endScript),
]
and sorryIUpsetYouScript = [
  ExpressionChange(Kolme, Neutral),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|...|j}),
  Speech(Kaxig, {j|... nah, you're good. i overreacted a bit, i'm sorry.|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|sometimes i get, i dunno. stupid. rejection is hard. not your fault though.|j},
  ),
  Speech(
    Kaxig,
    {j|well, uh. do you wanna just talk instead, or something?|j},
  ),
  Speech(
    Kaxig,
    {j|i mean i already told you what there is to know about me pretty much. dunno what else to say really.|j},
  ),
  Choice([|
    {
      text: "I also handle rejection poorly",
      result: rejectionSensitivityScript,
    },
    {text: "You should try to be less volatile", result: volatileScript},
    {text: "I like you", result: iLikeYouScript},
  |]),
]
and rejectionSensitivityScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|... you do?|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|well! guess that makes both of us losers!|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|i'm glad you get it, then. i mean i'm not glad you have RSD, that sucks bud. but we've got same brain at least.|j},
  ),
  Speech(
    Kaxig,
    {j|sometimes it's actually kinda nice when somebody else -|j},
  ),
  GoToScript(lowBatteryScript),
]
and volatileScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|ohh, is that what you think?? you think i have fucking anger management issues?|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|because you're completely right.|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|You could probably stand to be a bit less explosive, yes, but...|j},
  ),
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|You're not a bad person. You just have brain symptoms like the rest of us.|j},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(Kolme, {j|Yeah! We're all malfunctioning a bit, aren't we?|j}),
  ExpressionChange(Yksi, Anxious),
  ExpressionChange(Kaxig, Anxious),
  ExpressionChange(Kolme, Anxious),
  Narration({j|...|j}),
  Speech(Kaxig, {j|yeah. we sure are.|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, {j|anyway, yeah, i know. i should work on my -|j}),
  GoToScript(lowBatteryScript),
]
and iLikeYouScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|haha, what?|j}),
  Choice([|{text: "I said I like you", result: iLikeYou2Script}|]),
]
and iLikeYou2Script = [
  ExpressionChange(Kaxig, Surprised),
  Speech(Kaxig, {j|...!|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(
    Kaxig,
    {j|after i was a huge bitch to you just now? that's messed up, buddy.|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|... appreciate it though. not really used to being likeable, i guess.|j},
  ),
  Speech(Kaxig, {j|... i ... guess i kinda like -|j}),
  GoToScript(lowBatteryScript),
]
and lowBatteryScript = [
  GoToScript(endScript),
];
