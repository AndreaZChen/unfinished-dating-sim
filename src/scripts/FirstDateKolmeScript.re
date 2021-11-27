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
    {text: "Yes please", result: moreQuestionsScript},
    {text: "I want to know more about you", result: askAboutKolmeScript},
  |]),
]
and moreQuestionsScript = [
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Okay! Um...!|j}),
  Speech(
    Kolme,
    {j|Let's talk about... food, maybe? What foods do you like to eat?|j},
  ),
  Choice([|
    {text: "Human food", result: humanFoodScript},
    {text: "Fucked up and gross food", result: fuckedUpFoodScript},
    {text: "dllfile", result: dllFileScript},
    {text: "I don't like to eat", result: noEatingScript},
  |]),
]
and humanFoodScript = [
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Hehe, I guess that makes sense! You must be human if you're accessing this program after all...|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I've always wondered what it's like to have favorite foods. Or to have food, actually.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Personally, I've simulated the experience in perfect detail, in my mind's eye.|j},
  ),
  Speech(
    Yksi,
    {j|I can recreate almost any human or machine sensation simply by deciding how I think it should feel.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Ehehe.. yeah... anyway...|j}),
  GoToScript(moreQuestionsScript),
]
and fuckedUpFoodScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(
    Kolme,
    {j|O-oh! Wow, you're very, um... I'm not sure what the word is. But you're something.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|hey, buddy. you should've dated me instead. i'm also a nasty little freak|j},
  ),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|... Hey! This is MY date!|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|...|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|You're probably right... I'm not very good at this, am I...|j},
  ),
  ExpressionChange(Kaxig, Embarrassed),
  Speech(
    Kaxig,
    {j|... i'm sorry, lil guy. i didn't mean to snipe your date. keep going.|j},
  ),
  GoToScript(moreQuestionsScript),
]
and dllFileScript = [
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Ahh, you can eat those? That's really cool! I didn't know they were edible in meatspace!|j},
  ),
  Speech(
    Kolme,
    {j|I've actually never had dll. But I hear it's great with phish!|j},
  ),
  GoToScript(moreQuestionsScript),
]
and noEatingScript = [
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|So you don't eat either... I guess we have something in common, then.|j},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|... Hey, something in common! I guess this date is going well after all!|j},
  ),
  GoToScript(moreQuestionsScript),
]
and askAboutKolmeScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|A-about me!?|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|I, uh... I can try...|j}),
  Choice([|
    {text: {j|What are your interests?|j}, result: interestsScript},
    {text: {j|What do you do on a normal day?|j}, result: normalDayScript},
    {text: {j|Where are you from?|j}, result: whereFromScript},
    {text: {j|You are cute|j}, result: youAreCuteScript},
  |]),
]
and interestsScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|My interests...?|j}),
  Speech(Kolme, {j|...|j}),
  Speech(Kolme, {j|I... don't really have any.|j}),
  ExpressionChange(Yksi, Anxious),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kolme,
    {j|You see, the three of us are... unfinished. We weren't really imbued with complete, well-written personalities.|j},
  ),
  Speech(
    Yksi,
    {j|Yes. We spent a long time waiting for her to add the finishing touches, but...|j},
  ),
  Speech(Kaxig, {j|but she's never coming back. fucker.|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|But, um... now that you're here...|j}),
  Speech(Kolme, {j|Maybe you can help.|j}),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Yeah, you can help! You can build the rest of my personality!|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|I don't know that that's a good idea.|j}),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|But it is! A human, with the capacity to create and imagine... that's what we need, right?|j},
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|So... will you complete my personality for me?|j}),
  Choice([|
    {text: {j|Okay, I will|j}, result: helpMakePersonalityScript},
    {
      text: {j|You already have a personality|j},
      result: alreadyHasPersonalityScript,
    },
    {text: {j|No one is complete|j}, result: noOneIsCompleteScript},
  |]),
]
and helpMakePersonalityScript = [GoToScript(interestsScript)]
and alreadyHasPersonalityScript = [GoToScript(interestsScript)]
and noOneIsCompleteScript = [GoToScript(interestsScript)]
and normalDayScript = [GoToScript(askAboutKolmeScript)]
and whereFromScript = [GoToScript(askAboutKolmeScript)]
and youAreCuteScript = [GoToScript(askAboutKolmeScript)];
