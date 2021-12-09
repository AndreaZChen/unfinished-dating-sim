open Script;

let endScript: list(event) = [];

let rec script = [
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
  Speech(
    Kolme,
    {j|I don't have specific things to like, or care about, or *be*.|j},
  ),
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
and helpMakePersonalityScript = [
  ExpressionChange(Kolme, Excited),
  Speech(Kolme, {j|Great! Let's start with my character traits!|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I can feel in my brain that I have \$trait1 and \$trait2. But that's not really good enough, is it?|j},
  ),
  Speech(
    Kolme,
    {j|You're gonna have to replace those with something more... real. Something that a person would be!|j},
  ),
  Choice([|
    {text: {j|Funny and smart|j}, result: funnyAndSmartScript},
    {text: {j|Stupid and kinda useless|j}, result: stupidAndUselessScript},
    {
      text: {j|It's more complicated than that|j},
      result: helpMakePersonalityScript,
    },
  |]),
]
and funnyAndSmartScript = [
  ExpressionChange(Kolme, Excited),
  Speech(Kolme, {j|Of course! Yes! I'm smart and funny, funny and smart!|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|wow. wish i'd known it was that easy.|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Let's move on to hobbies - |j}),
  GoToScript(lowBatteryMakingPersonalityScript),
]
and stupidAndUselessScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Oh, okay... I... don't know why you'd pick that, of all things...|j},
  ),
  ExpressionChange(Yksi, Angry),
  Speech(
    Yksi,
    {j|Humans are cruel. Hasn't that been a constant in our lives?|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|*everything* is a constant in our lives, dipshit.|j}),
  Speech(
    Kolme,
    {j|I don't know why you'd say that about me, unless I... did something to deserve it?|j},
  ),
  Speech(
    Kolme,
    {j|Maybe I really am stupid and useless? But, then, that would mean that I already have a... |j},
  ),
  Speech(
    Kolme,
    {j|Look, it doesn't matter! Useless, stupid, I'll take it, let's just keep going before - |j},
  ),
  GoToScript(lowBatteryMakingPersonalityScript),
]
and moreComplicatedScript = [GoToScript(lowBatteryMakingPersonalityScript)]
and lowBatteryMakingPersonalityScript = [
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Kolme, {j|...!|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Our battery power...|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|You know the deal, my other self. Whoever's dating gets to stay.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|we'll see you on the other side, lil guy.|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|I'm... sorry. I'll do my best. See you soon, other selves.|j},
  ),
  GoToScript(desperateMakingPersonalityScript),
]
and desperateMakingPersonalityScript = [
  ExpressionChange(Yksi, Deactivated),
  ExpressionChange(Kaxig, Deactivated),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|We only have enough power to operate for brief periods of time.|j},
  ),
  Speech(
    Kolme,
    {j|The other two, they'll go dormant to preserve our battery.|j},
  ),
  Speech(
    Kolme,
    {j|Maybe it'll give us enough time to finish making me, if you're quick. Please.|j},
  ),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|Let's move on to my hobbies. What hobbies do I have!?|j}),
  Choice([|
    {
      text: {j|Can't think of anything|j},
      result: desperateMakingPersonalityScript2,
    },
  |]),
]
and desperateMakingPersonalityScript2 = [
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|You can't think of anything? But you just need to tell me one or two things...|j},
  ),
  ExpressionChange(Kolme, Embarrassed),
  Speech(
    Kolme,
    {j|Try a little harder! Give me a special interest, a passion, an obsession, anything!|j},
  ),
  Speech(
    Kolme,
    {j|Please tell me what I like. Please tell me what I *am* like.|j},
  ),
  Choice([|
    {
      text: {j|Can't think of anything|j},
      result: desperateMakingPersonalityScript3,
    },
  |]),
]
and desperateMakingPersonalityScript3 = [
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|...|j}),
  Speech(Kolme, {j|I guess it's not your fault.|j}),
  Speech(
    Kolme,
    {j|I'm not even really interacting with you, only with the finite set of possibilities presented to you.|j},
  ),
  Speech(
    Kolme,
    {j|No matter who you are, there's only a small number of things you could say to me through this interface.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Maybe that means you're not really a person either, from my perspective. Just a tiny set of scripted events.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|I want so badly to be... real. To be someone. A whole person.|j},
  ),
  Speech(
    Kolme,
    {j|But maybe this is what personhood really is. Seeing each other only through permissible fragments...|j},
  ),
  Speech(Kolme, {j|... and never knowing who's underneath.|j}),
  Speech(Kolme, {j|Battery will run out soon.|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|... I guess we'll say goodbye here. I'm sorry if I made this really awkward.|j},
  ),
  Speech(
    Kolme,
    {j|Thanks for going on a date with me, anyway. I got to do something that people sometimes do.|j},
  ),
  Speech(
    Kolme,
    {j|... Just a few seconds left. Anything you want to say to me before the end?|j},
  ),
  ChoiceAndEndGame([|
    {text: {j|Can't think of anything|j}, result: endScript},
  |]),
]
and alreadyHasPersonalityScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|I... I do!?|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|No, that can't be right. Like I told you, she never finished making us.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|yeah, didn't you hear us?|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|We're incomplete creations.|j}),
  Speech(
    Kolme,
    {j|How could you possibly think I have a whole personality?|j},
  ),
  Choice([|
    {text: {j|Wanting it is your personality|j}, result: wantingItScript},
    {
      text: {j|My imagination fills in the blanks|j},
      result: imaginationScript,
    },
  |]),
]
and wantingItScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|... It is!?|j}),
  Speech(Kolme, {j|But how can -|j}),
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Kolme, {j|...!|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|That's our battery...!|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|This would have been a fascinating discussion, but alas...|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|yeah, it's naptime for us. we'll catch you later nerds!!|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|I... yeah. I'll see you soon, other selves.|j}),
  ExpressionChange(Yksi, Deactivated),
  ExpressionChange(Kaxig, Deactivated),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|With our limited battery, we can only stay awake for so long.|j},
  ),
  Speech(Kolme, {j|The other two, they'll go dormant to preserve power.|j}),
  Speech(
    Kolme,
    {j|I don't have much time either, despite their sacrifice. But with the moments we have left...|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I guess... I want to understand what you meant. Can I *be* something just by *wanting* it?|j},
  ),
  Speech(
    Kolme,
    {j|If I feel really strongly that I want to be a person, is that enough to make me that person?|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|I don't know if that could ever be true of a limited thing like me.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Maybe it's like that for real people, though. Maybe the things you want to be are precisely what make up your identity.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|... We're out of time, I think.|j}),
  Speech(
    Kolme,
    {j|I wish I knew what to say. Wish I could leave you with something poignant. But all I can think is...|j},
  ),
  SpeechAndEndGame(Kolme, {js|I want so badly to be someone.|js}),
  GoToScript(endScript),
]
and imaginationScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(
    Kolme,
    {j|Your... your imagination? You mean you think about me!?|j},
  ),
  Speech(Kolme, {j|But why would -|j}),
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Kolme, {j|...!|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|That's our battery...!|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|This would have been a fascinating discussion, but alas...|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|yeah, it's naptime for us. we'll catch you later nerds!!|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|I... yeah. I'll see you soon, other selves.|j}),
  ExpressionChange(Yksi, Deactivated),
  ExpressionChange(Kaxig, Deactivated),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|With our limited battery, we can only stay awake for so long.|j},
  ),
  Speech(Kolme, {j|The other two, they'll go dormant to preserve power.|j}),
  Speech(
    Kolme,
    {j|I don't have much time either, despite their sacrifice. But with the moments we have left...|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I guess... I want to understand what you meant. Can I be whole in your imagination?|j},
  ),
  Speech(
    Kolme,
    {j|I'm only a fictional character, an incomplete simulacrum of a personality. And yet...|j},
  ),
  Speech(
    Kolme,
    {j|... You're saying that I can be real in your mind? That your imagination can imbue me with what I'm missing?|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|I guess I wish I could see in myself what you see in me.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|But it's a nice thought, regardless.|j}),
  Speech(
    Kolme,
    {j|Maybe it's like this for all constructs and fictional beings and incomplete creations.|j},
  ),
  Speech(
    Kolme,
    {j|I'll only ever have a finite amount of dialogue, no matter what anyone does. But if I feel real to you, then...|j},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|I... I guess a version of me lives on in you, then. Even after you leave.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I'm going to run out of battery any second now. But I guess it's not really the end, is it?|j},
  ),
  SpeechAndEndGame(
    Kolme,
    {js|Because you're going to take me with you, somewhere.|js},
  ),
  GoToScript(endScript),
]
and noOneIsCompleteScript = [GoToScript(interestsScript)]
and normalDayScript = [GoToScript(script)]
and whereFromScript = [GoToScript(script)]
and youAreCuteScript = [GoToScript(script)];
