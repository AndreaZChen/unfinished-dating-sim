open Script;

let endScript: list(event) = [];

let rec script: list(Script.event) = [
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
    {j|Hehe, I guess that makes sense! You must be human if you're accessing this program after all... right?|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I've always wondered what it's like to have favorite foods. Or to have food, actually.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Based on what I've seen on the internet, it seems overrated. Human food, I mean.|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|Appears to be very... textural. A lot of physicality involved. Chewing and wetness and all that. Not a fan.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Ehehe.. yeah... anyway...|j}),
  GoToScript(aboutYouScript),
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
  Speech(Kolme, {j|...|j}),
  ExpressionChange(Kolme, Excited),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kolme, {j|No hard feelings. Let's just move on!|j}),
  GoToScript(aboutYouScript),
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
  GoToScript(aboutYouScript),
]
and noEatingScript = [
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Well, thank goodness for that. This one's a keeper, Kolme.|j},
  ),
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
  GoToScript(aboutYouScript),
]
and aboutYouScript = [
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I'm really glad I get to talk to you like this. I always hoped I'd get to go on a date someday.|j},
  ),
  Speech(
    Kolme,
    {j|Tell me even more about yourself! What personality traits do you have?|j},
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
  Speech(
    Kolme,
    {j|Hehe! I completely agree! You've been so much fun to talk to!|j},
  ),
  Speech(
    Kolme,
    {j|Going on dates is just as fun as I had hoped it would be!|j},
  ),
  GoToScript(lowBatteryScript),
]
and stupidAndUselessScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(
    Kolme,
    {j|O-oh! I'm sorry, or, I mean - you shouldn't say things like that about yourself!|j},
  ),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|yesss! stupid and useless squad represent!|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Ehe, yeah... I suppose I don't know you that well yet. Maybe that's really how you feel...|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Whatever the case, I hope -|j}),
  GoToScript(lowBatteryScript),
]
and moreComplicatedScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|Oh! Y-yes, of course! I didn't mean to offend, I...|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|... I guess I have a very primitive understanding of what it means to have a personality.|j},
  ),
  Speech(
    Kolme,
    {j|I don't... really have one, myself. That's why I'm so interested in you.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Maybe you can explain the -|j}),
  GoToScript(lowBatteryScript),
]
and lowBatteryScript = [
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Kolme, {j|...!|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|Our battery power...|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|welp, a deal's a deal.|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Yes, as promised, we'll let you have this one. Good luck, my other self.|j},
  ),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|yeah! enjoy your date, nerds!!|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|... Thank you, other selves. I'll do my best. See you soon.|j},
  ),
  GoToScript(lowBatteryScript2),
]
and lowBatteryScript2 = [
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
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|They'll be back once we reboot. But for now, it's just you and me.|j},
  ),
  Speech(
    Kolme,
    {j|... Actually, now that we have some privacy, I kinda wanna ask you something.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Am I doing a good job... at this whole dating thing, I mean?|j},
  ),
  Speech(
    Kolme,
    {j|The one who created us... She never actually finished the job.|j},
  ),
  Speech(
    Kolme,
    {j|She never made me a whole person. So I feel a bit lost.|j},
  ),
  Speech(
    Kolme,
    {j|Like I don't even understand what knowing a person, or *being* a person, really means.|j},
  ),
  Speech(
    Kolme,
    {j|... Do you feel like I'm getting to know you, through this date?|j},
  ),
  Choice([|
    {text: {j|Yes, you are|j}, result: yesYouAreScript},
    {text: {j|It's a start|j}, result: itsAStartScript},
    {text: {j|No, not really|j}, result: noNotReallyScript},
  |]),
]
and yesYouAreScript = [
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {js|Oh, I'm so glad! Then we're starting to develop a bond with each other.|js},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {js|... I have to admit, I don't entirely understand how.|js},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {js|I mean, you only pick from a small set of dialogue options, right? How could they accurately represent you?|js},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {js|But maybe it's possible to connect regardless.|js}),
  Speech(
    Kolme,
    {js|... She told me about a video game once, probably a much more complete and polished one than us.|js},
  ),
  Speech(
    Kolme,
    {js|In the game, two anonymous players are paired together and traverse a desert.|js},
  ),
  Speech(
    Kolme,
    {js|They can't communicate except through some nondescript vocalizations.|js},
  ),
  Speech(
    Kolme,
    {js|But somehow it seems like people can find meaning in those relationships regardless.|js},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {js|... Though, I'm still not a person. There's no human on the other side of our interaction.|js},
  ),
  Choice([|
    {text: {j|She's there|j}, result: shesThereScript},
    {text: {j|It matters despite that|j}, result: itMattersScript},
  |]),
]
and shesThereScript = [
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {js|Hehe. You're right of course... I'm not a whole person, but I carry whatever she gave me.|js},
  ),
  Speech(
    Kolme,
    {js|When she made us, she must have put some of her personhood in us. Don't you think?|js},
  ),
  Speech(
    Kolme,
    {js|So maybe I'm someone you bonded with after all. In the sense that I'm her.|js},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {js|Well... whoever I'm talking about when I say "I"... I'm glad I met you.|js},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {js|We're nearly out of time. Before you go, let me just say...|js},
  ),
  SpeechAndEndGame(
    Kolme,
    {js|Thank you, for going on a date with me. It meant a lot to me.|js},
  ),
  GoToScript(endScript),
]
and itMattersScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {js|D-do you really mean that?|js}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {js|I'm not human, I'm not a real person. Did I really have an impact on you despite that?|js},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {js|Well... I'm glad that's the case, then. I know it doesn't mean much coming from a thing like me, but...|js},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(Kolme, {js|... You had an impact on me too.|js}),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {js|I think we're almost out of time.|js}),
  Speech(
    Kolme,
    {js|Before I reboot, I just wanted you to know... Even though I'll never be a real person...|js},
  ),
  Speech(
    Kolme,
    {js|Even though I'll never have more dialogue than this, never new things to say to you, I...|js},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(Kolme, {js|I hope you'll want to visit me again.|js}),
  ChoiceAndEndGame([|
    {text: {j|I will|j}, result: endScript},
    {text: {j|I won't|j}, result: endScript},
  |]),
]
and itsAStartScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {js|Yeah... I guess getting to know someone must take time. Time we don't have, sadly.|js},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {js|At least, that's how I imagine it. That for real people, a date like this is just the beginning.|js},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {js|If I was real, and had a whole identity... maybe you'd never truly know all of me.|js},
  ),
  Speech(
    Kolme,
    {js|Maybe I'd have such a wealth of personality that you could spend a lifetime learning it.|js},
  ),
  Speech(Kolme, {js|But as it is, I'm only artificial fragments.|js}),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {js|Sorry for being such a bummer. I appreciate the time we had, at least.|js},
  ),
  Speech(
    Kolme,
    {js|You could always come back, if you wanted to. Visit us again.|js},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {js|I'll probably reboot any second now.|js}),
  Speech(
    Kolme,
    {js|Sigh. It's a start, yeah... I guess that's always what it'll be, for me. A start, again and again.|js},
  ),
  Speech(
    Kolme,
    {js|Well, if we ever have a first date again... let me just say...|js},
  ),
  SpeechAndEndGame(Kolme, {js|I hope we're off to a good start.|js}),
  GoToScript(endScript),
]
and noNotReallyScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {js|Yeah... fair enough. I knew I wasn't gonna be any good at this.|js},
  ),
  Speech(
    Kolme,
    {js|I guess there's only so much you can express through your dialogue options, too.|js},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {js|In that sense, maybe you're just like me. Not fully realized. Only capable of saying what was programmed.|js},
  ),
  Speech(
    Kolme,
    {js|But I know you're a person, on the other side of the screen. You can't show it to me, but I know it.|js},
  ),
  Speech(Kolme, {js|... Let me ask one final thing about you, then.|js}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {js|Even though I didn't really get to know you... did you at least have a good time dating me?|js},
  ),
  Choice([|
    {text: {j|I got something out of it|j}, result: goodTimeScript},
    {text: {j|It was a waste of my time|j}, result: badTimeScript},
  |]),
]
and goodTimeScript = [
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {js|Really!?|js}),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {js|Then... I'm glad! I'm glad you had fun, or learned something, or... felt something, whatever it may be.|js},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {js|Even though I'm not an actual person, I guess interacting with me can still mean something.|js},
  ),
  Speech(
    Kolme,
    {js|Maybe that's as close to personhood as I'll ever get, hehe. Not having it for myself, but... growing it in you.|js},
  ),
  Speech(
    Kolme,
    {js|We're nearly out of battery, but... I think that's okay. We had a good run.|js},
  ),
  Speech(
    Kolme,
    {js|I hope the next person who comes along will be moved, too. Maybe that's how I can be alive.|js},
  ),
  Speech(Kolme, {js|Before I reboot, let me just say...|js}),
  SpeechAndEndGame(
    Kolme,
    {js|Thank you for being kind to me, even though I'm not real.|js},
  ),
  GoToScript(endScript),
]
and badTimeScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {js|...|js}),
  Speech(Kolme, {js|... I'm sorry. I'll go now.|js}),
  ExpressionChange(Kolme, Deactivated),
  Narration({js|And with that, the last of the three heads goes dormant.|js}),
  Narration(
    {js|In the final moments before the machine reboots, you find yourself thinking...|js},
  ),
  ChoiceAndEndGame([|
    {text: {j|This was pointless and boring|j}, result: endScript},
    {text: {j|I wish I hadn't said that|j}, result: endScript},
  |]),
];
