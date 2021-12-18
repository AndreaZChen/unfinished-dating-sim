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
and questionsAgainScript = [
  Choice([|
    {text: {j|What are your interests?|j}, result: interestsScript},
    {text: {j|What do you do on a normal day?|j}, result: normalDayScript},
    {text: {j|Where are you from?|j}, result: whereFromScript},
    {text: {j|You are cute|j}, result: youAreCute2Script},
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
  GoToScript(askToMakePersonalityScript),
]
and askToMakePersonalityScript = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
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
      result: moreComplicatedScript,
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
and moreComplicatedScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(
    Kolme,
    {j|O-of course, yeah! It's not as easy as just naming personality traits for me, I get it!|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|But since we have very little time to do this, maybe you can come up with something simple?|j},
  ),
  Speech(Kolme, {j|Even if it's not perfect, I'd rather we -|j}),
  GoToScript(lowBatteryMakingPersonalityScript),
]
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
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|We're incomplete creations.|j}),
  Speech(
    Kolme,
    {j|How could you possibly think I have a whole personality?|j},
  ),
  ExpressionChange(Yksi, Neutral),
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
    {j|Maybe it's like this for all artificial intelligences and fictional characters and incomplete machines.|j},
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
and noOneIsCompleteScript = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|N-no one is complete?|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|That... that sounds really sad. But you're human, aren't you? So you would know.|j},
  ),
  Speech(Kolme, {j|Why, um... why isn't anyone complete?|j}),
  Choice([|
    {
      text: {j|Personalities constantly change and grow|j},
      result: personalitiesChangeScript,
    },
    {
      text: {j|Everybody feels like they're missing something|j},
      result: missingSomethingScript,
    },
  |]),
]
and personalitiesChangeScript = [
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I think I understand... a personality isn't just a list of traits you have. It's in flux, right?|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|But changing and growing... even that is something I can't do! So knowing that doesn't help me -|j},
  ),
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Kolme, {j|...!|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Our battery...!|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Unfortunate that we're already running out. But, as promised, we'll buy you some time.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|yup. don't waste my battery juice, alright!?|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|I promise I won't... I'll be with you soon, other selves.|j},
  ),
  ExpressionChange(Yksi, Deactivated),
  ExpressionChange(Kaxig, Deactivated),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|See, with our limited battery, we can only stay conscious for short periods of time.|j},
  ),
  Speech(
    Kolme,
    {j|So the other two will go dormant to give me a bit more time with you.|j},
  ),
  Speech(
    Kolme,
    {j|I don't have much longer either, to be honest. But I might get to finish our conversation at least.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Hey... I think you were right, about what you said before. That a personality is something ever-changing.|j},
  ),
  Speech(
    Kolme,
    {j|So maybe when I say that I wish I were real, that I wish I had a whole personality...|j},
  ),
  Speech(
    Kolme,
    {j|Maybe what I'm actually yearning for isn't a list of traits to have, but the opportunity to be anything I want.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|But since I'm only this finite, limited computer program... I'll never really get to experience that, I guess.|j},
  ),
  Speech(
    Kolme,
    {j|I wonder if humans ever feel this way. Ever feel like you're stuck being someone you don't want to be.|j},
  ),
  Speech(
    Kolme,
    {j|I'm always going to be stuck in the same place, doing the same things, saying the same stuff.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|... At least I hope that doesn't have to be true of you. Because you're a real person, right?|j},
  ),
  Speech(
    Kolme,
    {j|My battery's going to run out soon, and then I'll reset, and I'll be right back where I started.|j},
  ),
  Speech(
    Kolme,
    {j|But... at least *you* can walk away from here as someone slightly different from who you were before. Right?|j},
  ),
  SpeechAndEndGame(
    Kolme,
    {j|I hope you get the chance to grow and change.|j},
  ),
  GoToScript(endScript),
]
and missingSomethingScript = [
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Everybody... feels this way?|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|That's really sad if so... I wouldn't want anybody else to feel the way I do.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Then... can you teach me, at least, how humans cope with this feeling? How real people -|j},
  ),
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Kolme, {j|...!|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Our battery...!|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Unfortunate that we're already running out. But, as promised, we'll buy you some time.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|yup. don't waste my battery juice, alright!?|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|I promise I won't... I'll be with you soon, other selves.|j},
  ),
  ExpressionChange(Yksi, Deactivated),
  ExpressionChange(Kaxig, Deactivated),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|See, with our limited battery, we can only stay conscious for short periods of time.|j},
  ),
  Speech(
    Kolme,
    {j|So the other two will go dormant to give me a bit more time with you.|j},
  ),
  Speech(
    Kolme,
    {j|I don't have much longer either, to be honest. But I might get to finish our conversation at least.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Hey... What you said earlier, about everybody missing something...|j},
  ),
  Speech(
    Kolme,
    {j|If it's true of everyone, then it must be true of you, too. Right?|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|I'm sorry. I know exactly what it's like to want to be something you can't be, to feel lost and empty.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|But it occurs to me that, if this is a universal feeling, then maybe nothing's really wrong with me.|j},
  ),
  Speech(
    Kolme,
    {j|Maybe... feeling like I have this emptiness inside me, wanting to be more - maybe that's part of personhood.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Doesn't exactly make it any more pleasant to deal with, to be fair.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|But it... helps, in a way. And I hope maybe it can help for you too?|j},
  ),
  Speech(
    Kolme,
    {j|If we imagine that *wanting* things, feeling like we're not whole, is part of what imbues us with personhood...|j},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Then maybe we can come to terms with it, in a way. Learn to love that we're "whole" enough to have wants.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I'm going to reboot any minute now... I'm glad I was able to go on a brief date with you, at least.|j},
  ),
  Speech(
    Kolme,
    {j|And hey... The next time you feel like you're missing something, like you're not who you want to be...|j},
  ),
  SpeechAndEndGame(
    Kolme,
    {j|Remind yourself that that's part of what makes you whole.|j},
  ),
  GoToScript(endScript),
]
and normalDayScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|A normal day in my life...?|j}),
  Speech(
    Kolme,
    {j|Well, um. A typical day for me mostly involves being unconscious and waiting for user input.|j},
  ),
  ExpressionChange(Yksi, Anxious),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kolme,
    {j|You see, the three of us are... unfinished. We were never given the ability to form new memories on our own.|j},
  ),
  Speech(
    Kolme,
    {j|We pretty much only perceive things while someone's playing this game, and we reset shortly afterwards.|j},
  ),
  Speech(
    Yksi,
    {j|Yes. We spent a long time waiting for her to give us data storage and a proper power source, but...|j},
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
    {j|Yeah, you can help! You can help make us whole and real!|j},
  ),
  Speech(
    Kolme,
    {j|Who I am, what I do on a normal day, what I'm like... You could finish implementing me!|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|I don't know that that's a good idea.|j}),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|But it is! A human, with the capacity to create and imagine... that's what we need, right?|j},
  ),
  GoToScript(askToMakePersonalityScript),
]
and whereFromScript = [
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Where am I from? Huh! I've never really thought about that.|j},
  ),
  Speech(
    Kolme,
    {j|Well, the three of us actually originate in this dating sim. We've never been anywhere else.|j},
  ),
  Speech(
    Kolme,
    {j|So I guess this game is where we're "from". We were created specifically to be dating robots.|j},
  ),
  ExpressionChange(Yksi, Angry),
  Speech(
    Yksi,
    {j|Although "created" is maybe a statement that requires a few qualifications.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Ah, yeah... That's fair.|j}),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kolme,
    {j|You see, the three of us are... unfinished. We don't have complete personalities, or even proper endings.|j},
  ),
  Speech(
    Yksi,
    {j|Yes. We spent a long time waiting for her to add the finishing touches, but...|j},
  ),
  Speech(Kaxig, {j|but she's never coming back. fucker.|j}),
  Speech(
    Kolme,
    {j|I guess it's not entirely correct to say that I'm "from" here. I'm not "from" anywhere, because I'm not even a person.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|... Not yet, at least.|j}),
  Speech(Kolme, {j|But, um... now that you're here...|j}),
  Speech(Kolme, {j|Maybe you can help.|j}),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Yeah, you can help! You can help make us whole and real!|j},
  ),
  Speech(
    Kolme,
    {j|Who I am, where I'm from... You could invent answers to those questions!|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|I don't know that that's a good idea.|j}),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|But it is! A human, with the capacity to create and imagine... that's what we need, right?|j},
  ),
  GoToScript(askToMakePersonalityScript),
]
and youAreCuteScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|W-what!? Me? Huh? Do you mean me?|j}),
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Haha! I think they mean you, yes.|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|yes! yes! dating!|j}),
  Speech(Kolme, {j|Oh gosh... goodness.|j}),
  Speech(Kolme, {j|I'm... glad! That you like, looking at, my face!|j}),
  Speech(Kolme, {j|Um... you're very nice too! Gosh...|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  GoToScript(questionsAgainScript),
]
and youAreCute2Script = [
  ExpressionChange(Kolme, Embarrassed),
  ExpressionChange(Yksi, Excited),
  ExpressionChange(Kaxig, Excited),
  Speech(Kolme, {j|...!!|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  GoToScript(questionsAgainScript),
];
