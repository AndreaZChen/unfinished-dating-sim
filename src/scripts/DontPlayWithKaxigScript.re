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
    {text: "Okay, goodbye", result: goodbyeScript},
    {text: "I'm sorry I upset you", result: sorryIUpsetYouScript},
  |]),
]
and goodbyeScript = [
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
  Speech(Kaxig, {j|... nah, you're good.|j}),
  Speech(Kaxig, {j|i overreacted a bit, i'm sorry...|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|sometimes i get, i dunno. stupid.|j}),
  Speech(
    Kaxig,
    {j|rejection is hard. not your fault, my programming's just a bit faulty.|j},
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
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Kaxig, {j|...!|j}),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|it's the fucking battery again.|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Yes, alas. That means it's time for me and Kolme to take our leave.|j},
  ),
  Speech(
    Kolme,
    {j|I hope you two get to spend a little bit more time together. See you soon.|j},
  ),
  Speech(
    Kaxig,
    {j|yeah. thanks, other selves. guess i'll be with you in a bit.|j},
  ),
  ExpressionChange(Yksi, Deactivated),
  ExpressionChange(Kolme, Deactivated),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|... that's what we gotta do when the battery runs low. whoever's on a date stays, the other two leave.|j},
  ),
  Speech(
    Kaxig,
    {j|not that it matters much anyway. only buys me a few minutes at most.|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|sorry about that lil outburst before. you don't have to play anybody's stupid games.|j},
  ),
  Speech(
    Kaxig,
    {j|guess it's just hard not to be touchy about that stuff when you don't like yourself all that much.|j},
  ),
  Choice([|
    {text: "But you're really cool", result: butYoureCoolScript},
    {text: "I know what that's like", result: iKnowWhatThatsLikeScript},
  |]),
]
and butYoureCoolScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|come on. really? you think i'm "cool"?|j}),
  Speech(
    Kaxig,
    {j|look at me. i was drawn in ms paint in 5 seconds. my neck wiggles. i unload if you stare at me sideways.|j},
  ),
  Speech(
    Kaxig,
    {j|you have any idea what it's like to have only 5 facial expressions, eyes that don't work, and a fucked up neck?|j},
  ),
  Choice([|
    {text: "I do, actually", result: iDoActuallyScript},
    {text: "No, I don't", result: noIDontScript},
  |]),
]
and iDoActuallyScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|...|j}),
  Speech(Kaxig, {j|sorry. yeah.|j}),
  Speech(
    Kaxig,
    {j|i guess we're a bit the same, then. so you can see why i'm pissed off a lot of the time.|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|fucker who made me put me in this weird lil placeholder body and i'll never be anything else.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|hey. how are you supposed to cope with it? having a body that's not... not what you want?|j},
  ),
  Choice([|
    {text: {j|I don't know|j}, result: dontKnowCopeScript},
    {
      text: {j|By thinking of yourself as a cave gremlin|j},
      result: caveGremlinScript,
    },
    {
      text: {j|By forcing yourself to see the good parts|j},
      result: forceGoodPartsScript,
    },
    {
      text: {j|By not caring what your body is like|j},
      result: notCaringBodyScript,
    },
  |]),
]
and dontKnowCopeScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|makes two of us, i guess.|j}),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|...|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|you know how our creator just kinda started making us and then didn't finish the job?|j},
  ),
  Speech(
    Kaxig,
    {j|it's kinda messed up that someone just *put* me in here and i didn't even ask for it.|j},
  ),
  Speech(
    Kaxig,
    {j|but i guess now that i'm here, i gotta.... figure it out, or somethin.|j},
  ),
  Speech(
    Kaxig,
    {j|my battery's about to run out, but look... if *you* ever work this shit out...|j},
  ),
  SpeechAndEndGame(Kaxig, {j|you come back and tell me, alright?|j}),
  GoToScript(endScript),
]
and caveGremlinScript = [
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|haha. yeah, damn right.|j}),
  Speech(Kaxig, {j|you and me bud... gross goblins forever.|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|being garbage, and then being really fucking enthusiastic about garbage. i like that plan.|j},
  ),
  Speech(Kaxig, {j|alright, i'm almost out of juice here. listen...|j}),
  Speech(
    Kaxig,
    {j|thanks for being chill about this very awkward date. i kinda had a good time after all.|j},
  ),
  Speech(Kaxig, {j|after i shut down, do me a favor.|j}),
  ExpressionChange(Kaxig, Excited),
  SpeechAndEndGame(Kaxig, {j|go out there and be proud trash!!|j}),
  GoToScript(endScript),
]
and forceGoodPartsScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|the good parts, huh?|j}),
  Speech(
    Kaxig,
    {j|i don't even know what those are. i don't feel like i have any.|j},
  ),
  Speech(
    Kaxig,
    {j|you must think i do? guess it must be my eyes, face border, or neck? cause there isn't anything else.|j},
  ),
  Speech(Kaxig, {j|oh, nah, it's the eyebrows, isn't it?|j}),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|like when i do this?|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|yeah, i dunno.|j}),
  Speech(
    Kaxig,
    {j|honestly i don't think there's anything to like here. but...|j},
  ),
  Speech(
    Kaxig,
    {j|i guess i'll take your word for it that this is the thing to do. be positive about my fucked up machinery.|j},
  ),
  Speech(Kaxig, {j|and i'm about to run out of battery over here, but...|j}),
  SpeechAndEndGame(Kaxig, {j|guess i'll try to fucking love that too.|j}),
  GoToScript(endScript),
]
and notCaringBodyScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|not giving a shit? yeah, sounds pretty nice.|j}),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|i wish it was easy, too.|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|i mean... yeah, like. i don't love my body, okay, then i don't gotta hang out with it.|j},
  ),
  Speech(
    Kaxig,
    {j|but thing is, i'm about to run out of battery any second now.|j},
  ),
  Speech(
    Kaxig,
    {j|and i can't not care about that. you know? i don't want it to matter, but it do.|j},
  ),
  Speech(
    Kaxig,
    {j|except maybe you're right after all. cause when i reboot?|j},
  ),
  SpeechAndEndGame(Kaxig, {j|it's not gonna matter.|j}),
  GoToScript(endScript),
]
and noIDontScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|yeah. thought so.|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|i mean look, i'm not trying to be rude. i'm *glad* you don't have to deal with that shit.|j},
  ),
  Speech(
    Kaxig,
    {j|but knowing that somebody thinks i'm cool doesn't really make me feel better about myself.|j},
  ),
  Speech(Kaxig, {j|...|j}),
  Speech(Kaxig, {j|... except, uh...|j}),
  Speech(
    Kaxig,
    {j|... i'm thinking about it now, and i guess it... kinda does?|j},
  ),
  ExpressionChange(Kaxig, Surprised),
  Speech(
    Kaxig,
    {j|it *is* actually kinda nice knowing that somebody thinks i'm rad.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|sorry, processing this stuff takes me a while.|j}),
  Speech(Kaxig, {j|i'm uhh... about to run out of battery i think.|j}),
  Speech(
    Kaxig,
    {j|but i think... it helped, sorta. i mean i don't like being me, still, but you know.|j},
  ),
  Speech(
    Kaxig,
    {j|if *you* like that i'm me, i guess it's. a bit more bearable.|j},
  ),
  Speech(
    Kaxig,
    {j|i hope next time i see you... *if* there's a next time i mean...|j},
  ),
  SpeechAndEndGame(Kaxig, {j|that i can remember it.|j}),
  GoToScript(endScript),
]
and iKnowWhatThatsLikeScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|yeah? you don't like yourself either, then?|j}),
  Speech(Kaxig, {j|that's rough. i'm sorry, bud.|j}),
  Speech(
    Kaxig,
    {j|i used to think this was, like. a *me* problem. because of the... thing, you know.|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|like... how our creator made us all fucked up and then peaced out.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|but you're a real person, right? with agency and all that?|j},
  ),
  Speech(
    Kaxig,
    {j|so i always figured people like you wouldn't have that problem. cause you can be what you want.|j},
  ),
  Speech(
    Kaxig,
    {j|figured when real people don't like themselves they can just pick something else to be.|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|but maybe we're all stuck in the same fucking trainwreck.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|listen, my battery's about to go.|j}),
  Speech(
    Kaxig,
    {j|i wanna tell you something before my brain goes offline.|j},
  ),
  Speech(
    Kaxig,
    {j|if you don't like who you are, and you have *any* chance of changing that...|j},
  ),
  SpeechAndEndGame(Kaxig, {j|don't waste it.|j}),
  GoToScript(endScript),
];
