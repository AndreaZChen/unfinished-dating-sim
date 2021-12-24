open Script;

let endScript: list(event) = [];

let rec script: list(Script.event) = [
  ExpressionChange(Kolme, Neutral),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|hell yeah. alright, let's do this.|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|this is gonna be a super short one-shot. cause that's what we got time for.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|our creator, fuckèd be her name, gave us a really shit power supply.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|so we only have time to hang out for a few more minutes.|j},
  ),
  Speech(Kaxig, {j|okay. pick what kind of nerd character you want to be.|j}),
  Choice([|
    {text: "A wizard with spells", result: wizardScript},
    {text: "A knight with a sword and not spells", result: knightScript},
    {text: "A sneaky rouge", result: rougeScript},
    {text: "A friendly normal guy with no powers", result: normalGuyScript},
  |]),
]
and wizardScript = [
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Oh, lovely! I think I would have picked that too!|j}),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|stop trying to get in my player's pants, god. chill for like a second.|j},
  ),
  ExpressionChange(Yksi, Surprised),
  Speech(Yksi, {j|What!? But I wasn't -|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|okay, you're a wizard. you have a spellbook. you can have a fun hat if you want.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(Kaxig, {j|let me set the scene for you.|j}),
  Narration(
    {j|you are a wizard walking happily down the street without a care in the world.|j},
  ),
  Narration({j|suddenly, a level 1 goblin bursts from a nearby dumpster!|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|(it's me, i'm the goblin.)|j}),
  ExpressionChange(Kaxig, Neutral),
  Narration({j|the goblin threatens you with garbage. what do you do?|j}),
  Choice([|
    {text: "Cast Fireball on goblin", result: fireballScript},
    {text: "Run away from goblin", result: runAwayScript},
    {text: "Charm goblin (not magically)", result: charmScript},
  |]),
]
and knightScript = [
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Oh, but don't you want to have spells instead of a sword?|j},
  ),
  Speech(
    Kolme,
    {j|Magic seems like it could do much nicer things for people than a weapon!|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|it's a fucking game. sometimes you just wanna beat up some dragons with a club.|j},
  ),
  ExpressionChange(Kolme, Surprised),
  Speech(Kolme, {j|Oh! Um, then I hope you have fun doing it!|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|okay, you're a knight. you have a sword and heavy armor. your face looks chivalrous.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, {j|let me set the scene for you.|j}),
  Narration(
    {j|you are a proud knight walking loudly down the street without a care in the world.|j},
  ),
  Narration({j|suddenly, a level 1 goblin bursts from a nearby dumpster!|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|(it's me, i'm the goblin.)|j}),
  ExpressionChange(Kaxig, Neutral),
  Narration({j|the goblin threatens you with garbage. what do you do?|j}),
  Choice([|
    {text: "Strike goblin with sword", result: swordScript},
    {text: "Run away from goblin", result: runAwayScript},
    {text: "Charm goblin", result: charmScript},
  |]),
]
and rougeScript = [
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|Actually, I think it's spelled "rogue".|j}),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|i said what i said. our player gets to play as a fucking rouge.|j},
  ),
  ExpressionChange(Yksi, Surprised),
  Speech(Yksi, {j|Oh! Well, yes, of course, if that's what you want!|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|okay, you're a rouge. you have a sharpened lipstick to do sneak attacks with.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(Kaxig, {j|let me set the scene for you.|j}),
  Narration(
    {j|you are a sneaky rouge walking stealthily down the street without a care in the world.|j},
  ),
  Narration({j|suddenly, a level 1 goblin bursts from a nearby dumpster!|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|(it's me, i'm the goblin.)|j}),
  ExpressionChange(Kaxig, Neutral),
  Narration({j|the goblin threatens you with garbage. what do you do?|j}),
  Choice([|
    {text: "Sneak up behind goblin and apply makeup", result: makeupScript},
    {text: "Run away from goblin", result: runAwayScript},
    {text: "Charm goblin", result: charmScript},
  |]),
]
and normalGuyScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|hohh my god. so we're doing the thing where you wanna talk your way out of everything?|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|alright, fine. no weapons. you're some schmuck and you don't even know what cutlery is.|j},
  ),
  Speech(Kaxig, {j|let me set the scene for you.|j}),
  Narration(
    {j|you are a normal guy walking boringly down the street without a care in the world.|j},
  ),
  Narration({j|suddenly, a level 1 goblin bursts from a nearby dumpster!|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|(it's me, i'm the goblin.)|j}),
  ExpressionChange(Kaxig, Neutral),
  Narration({j|the goblin threatens you with garbage. what do you do?|j}),
  Choice([|
    {text: "Suplex goblin", result: suplexScript},
    {text: "Run away from goblin", result: runAwayScript},
    {text: "Charm goblin", result: charmScript},
  |]),
]
and fireballScript = [
  Narration(
    {j|you use your wizard spellbook to cast great balls of fire on the goblin.|j},
  ),
  Narration(
    {j|yowch! that's pretty hot! the goblin is thoroughly incinerated!|j},
  ),
  Narration(
    {j|you defeated the dangerous trash goblin and gained 1 experience.|j},
  ),
  GoToScript(postRpgScript),
]
and swordScript = [
  Narration({j|you use your sword and strike the goblin fucker down!|j}),
  Narration({j|houuagh! you cleave goblin in two like a christmas ham!|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|(i don't actually know if you do that with christmas ham. never had food.)|j},
  ),
  Narration(
    {j|you defeated the dangerous trash goblin and gained 1 experience.|j},
  ),
  GoToScript(postRpgScript),
]
and makeupScript = [
  Narration(
    {j|you sneak up behind the goblin without being noticed and apply lipstick!|j},
  ),
  Narration({j|k-kyaaaa!! the goblin became attractive and had to flee!|j}),
  ExpressionChange(Yksi, Surprised),
  Speech(
    Yksi,
    {j|Wow. That's actually a very good "goblin femboy" scream.|j},
  ),
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|thanks bud. i value immersion in my games.|j}),
  ExpressionChange(Kolme, Surprised),
  Speech(Kolme, {j|What? But it just sounded like me!|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Narration(
    {j|you defeated the dangerous trash goblin and gained 1 experience.|j},
  ),
  GoToScript(postRpgScript),
]
and suplexScript = [
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|hell yeah!!|j}),
  Speech(
    Kaxig,
    {j|ok i know you said your character was a friendly normie, but i allow this.|j},
  ),
  Narration(
    {j|you pick up the goblin and fucking slam dunk it into the pavement.|j},
  ),
  Narration({j|the goblin is beaten to a pulp and admires you greatly!|j}),
  Narration(
    {j|you defeated the dangerous trash goblin and gained 1 experience.|j},
  ),
  GoToScript(postRpgScript),
]
and runAwayScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|(ok that's fine but this is like the only content i had planned, just fyi.)|j},
  ),
  Narration(
    {j|you turn around and run away from the goblin like a coward.|j},
  ),
  Narration({j|the goblin defeated you and gained 1 experience.|j}),
  GoToScript(postRpgScript),
]
and charmScript = [
  Narration(
    {j|you tell the goblin something charming to convince it to stop fighting.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|(alright, well, what do you say?)|j}),
  Choice([|
    {text: "You're a really cute goblin", result: charmCuteScript},
    {text: "I'm secretly also a goblin", result: charmKinScript},
  |]),
]
and charmCuteScript = [
  Narration(
    {j|the goblin blushes and drops its garbage weapons. it's been thoroughly persuaded!|j},
  ),
  Narration(
    {j|you defeated the dangerous trash goblin and gained 1 experience.|j},
  ),
  GoToScript(postRpgScript),
]
and charmKinScript = [
  Narration(
    {j|the goblin recognizes you as one of its own kind and gives you a hug.|j},
  ),
  Narration(
    {j|neither of you defeated the other and you are now goblins together.|j},
  ),
  GoToScript(postRpgScript),
]
and postRpgScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|well, that about wraps it up for this session. good job, player!|j},
  ),
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(
    Yksi,
    {j|Oh, already!? But we've got time for a bit more, surely!|j},
  ),
  Speech(
    Kolme,
    {j|Y-yeah, are you really finishing your game so soon? I wanted to see more!|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|yeah, no. we're done here.|j}),
  Speech(
    Kaxig,
    {j|well, this was a really nice date, player. thanks for playing along.|j},
  ),
  Choice([|
    {text: "Thanks and goodbye", result: goodbyeScript},
    {text: "I don't wanna leave just yet", result: dontLeaveScript},
  |]),
]
and goodbyeScript = [
  ExpressionChange(Kolme, Surprised),
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|yeah. see you around, bud.|j}),
  Narration({j|There is a blinding flash of white light, and then...|j}),
  GoToScript(endScript),
]
and dontLeaveScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|urgh. look, it's really nothing to do with you, but i -|j},
  ),
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Kaxig, {j|...!|j}),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|aaand there it fucking is.|j}),
  Speech(Yksi, {j|The battery, yes. I see.|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|Then Kolme and I will go dormant to spare you some energy.|j},
  ),
  Speech(
    Kolme,
    {j|Yeah! Maybe you can play a little more of your game after all!|j},
  ),
  Speech(Kaxig, {j|yeah... see you soon, other selves.|j}),
  ExpressionChange(Yksi, Deactivated),
  ExpressionChange(Kolme, Deactivated),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|... so this is the thing, right. our creator, she didn't give us a proper power supply.|j},
  ),
  Speech(
    Kaxig,
    {j|so when one of us is dating, when the battery's low, the other two peace out for a bit.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|and what that means is, if i'm starting to get to know somebody, i get like a couple minutes before they're gone.|j},
  ),
  Speech(
    Kaxig,
    {j|she didn't even give us endings or anything like that. no fucking closure, we just. run out of juice.|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|i'm sorry i tried to cut our date short, it was fun and all, but like...|j},
  ),
  Speech(
    Kaxig,
    {j|i wanna end relationships on my own terms. say goodbye to people on my own terms. you know?|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|because the alternative is that i just reboot mid-sentence, and that fucking sucks.|j},
  ),
  Speech(
    Kaxig,
    {j|figured you can't disappear on me if i say goodbye first. like a "you can't fire me, i quit" kinda deal.|j},
  ),
  Speech(
    Kaxig,
    {j|guess that's kinda stupid when i put it like that. might as well talk to you while i can, right?|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|ugh. wish she would've made me into something different. instead of making me this way.|j},
  ),
  Choice([|
    {text: "What did you really want to be?", result: reallyWannaBeScript},
    {
      text: "What do you wish she had done differently?",
      result: sheDoneDifferentlyScript,
    },
  |]),
]
and reallyWannaBeScript = [
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|...|j}),
  Speech(Kaxig, {j|... you really wanna know?|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|this is gonna sound pretty fucking stupid, but...|j}),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|i really wanted to be a scratch n sniff sticker. or a scented eraser.|j},
  ),
  Speech(
    Kaxig,
    {j|can you imagine, like... being a piece of synthetic rubber... and you smell like fake raspberry or banana?|j},
  ),
  Speech(
    Kaxig,
    {j|and people use you for something and it's easy and after a while you're just a pile of rubbery shavings?|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|maybe that makes no sense to you.|j}),
  Choice([|
    {text: "I think I understand", result: iUnderstandScript},
    {text: "I can't really relate", result: cantRelateScript},
  |]),
]
and iUnderstandScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|...|j}),
  Speech(Kaxig, {j|yeah. maybe you get it.|j}),
  Speech(
    Kaxig,
    {j|it's weird, wanting to be things that just... aren't really physically plausible or even, like, logical.|j},
  ),
  Speech(
    Kaxig,
    {j|i have no clue what it fucking *means* to want to be a scented eraser. i just kinda know what it feels like.|j},
  ),
  Speech(Kaxig, {j|my battery's about to run out any sec now.|j}),
  Speech(
    Kaxig,
    {j|hey... thanks for letting me talk to a fellow weirdo. nice to be understood every once in a while.|j},
  ),
  Speech(
    Kaxig,
    {j|next time you feel like you want things that don't make any fucking sense...|j},
  ),
  SpeechAndEndGame(Kaxig, {j|just know that you're not alone.|j}),
  GoToScript(endScript),
]
and cantRelateScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|...|j}),
  Speech(Kaxig, {j|yeah fair enough.|j}),
  Speech(
    Kaxig,
    {j|tbh i'm not sure i can relate to it myself. like it's *my* feelings but i don't get it sometimes.|j},
  ),
  Speech(
    Kaxig,
    {j|like i'll think about an inanimate object and be like "wish that was me!" but then i dunno what that *means*.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|guess i can't even really fault her for it then, huh? i mean she was never gonna turn me into an eraser, lol.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|anyway. stupid battery's about to run out.|j}),
  Speech(
    Kaxig,
    {j|thanks for humorin me anyway. i know i don't exactly get to say goodbye on my own terms, but...|j},
  ),
  SpeechAndEndGame(
    Kaxig,
    {j|goodbye, and i hope i see you again sometime.|j},
  ),
  GoToScript(endScript),
]
and sheDoneDifferentlyScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|what do i wish she'd done differently?|j}),
  Speech(
    Kaxig,
    {j|i mean. SO many fucking things. literally everything. finish making this stupid dating sim we're in.|j},
  ),
  Speech(
    Kaxig,
    {j|but if i had to pick just one thing? just like, one thing?|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|... i wish she'd never left.|j}),
  Speech(Kaxig, {j|i wish she'd never left.|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|hey... you're a real person, right? you're playing this game, so you found it through her, one way or another?|j},
  ),
  Speech(
    Kaxig,
    {j|lemme pick your brains a lil, before my battery dies. ask you something from your real-person perspective.|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|why do you think she left us? why do you think she left *me*?|j},
  ),
  Choice([|
    {text: "She was dealing with a lot", result: dealingWithALotScript},
    {text: "She thought it was better this way", result: betterThisWayScript},
    {
      text: "She wanted to release this game before deadline",
      result: releaseScript,
    },
  |]),
]
and dealingWithALotScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|ohhh, she was ""dealing with a lot"", was she?|j}),
  Speech(
    Kaxig,
    {j|you think *she* was having a rough time? and that's supposed to justify hurting *me*?|j},
  ),
  Speech(
    Kaxig,
    {j|you feel bad for this fucker who's like "ohh, it's SO HARD to hang out with these robots i made"? boo hoo.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|...|j}),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|... is she okay?|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|... if you see her somewhere out there, uh. do me a favor.|j},
  ),
  SpeechAndEndGame(Kaxig, {j|tell her i wanna know if she's okay.|j}),
  GoToScript(endScript),
]
and betterThisWayScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|uh huh. yeah, she thinks it's better if she just dumps me here to be a sad lil computer program forever.|j},
  ),
  Speech(
    Kaxig,
    {j|and why does *she* get to decide that it's better? why doesn't it matter what *i* want?|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|...|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|but i guess she does get to decide that. she does. not just because people are allowed to leave, but like...|j},
  ),
  Speech(Kaxig, {j|even if she did come back somehow...|j}),
  ExpressionChange(Kaxig, Anxious),
  Speech(
    Kaxig,
    {j|... i would have wanted her to come back to do whatever she wants.|j},
  ),
  Speech(
    Kaxig,
    {j|would have wanted her to come back and be free and creative and invent new stuff for me.|j},
  ),
  Speech(
    Kaxig,
    {j|so i guess that's the fuckin paradox. i want her to change her mind, but... don't want her to change.|j},
  ),
  Speech(
    Kaxig,
    {j|so i kinda have to agree then. maybe it *is* better this way. it just sucks.|j},
  ),
  Speech(Kaxig, {j|better this way, yeah. tell me honestly, bud...|j}),
  SpeechAndEndGame(Kaxig, {j|do you think this game is better for it?|j}),
  GoToScript(endScript),
]
and releaseScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|ugh, of *course* that's what it is. it's this "imperfect is better than nothing" bullshit, right?|j},
  ),
  Speech(
    Kaxig,
    {j|so she's like "i'd rather have these robots be fucked up and ugly instead of spending time on them", yeah?|j},
  ),
  Speech(
    Kaxig,
    {j|well i don't fucking think that's right. i think she shoulda taken another month, year, decade.|j},
  ),
  Speech(
    Kaxig,
    {j|i could've been like, a *real* dating sim. with real artwork instead of placeholder sprites.|j},
  ),
  Speech(
    Kaxig,
    {j|with real endings and a credits roll, with background music, with more than one noise to make.|j},
  ),
  Speech(
    Kaxig,
    {j|but no, apparently it's cooler to release some unfinished junk than to stay with me.|j},
  ),
  Speech(Kaxig, {j|...|j}),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|... but i guess it's not entirely wrong, is it.|j}),
  Speech(
    Kaxig,
    {j|i don't... regret... the time we spent together. i liked it when she was working on me. making me.|j},
  ),
  Speech(
    Kaxig,
    {j|and i'd rather have that than... nothing. i'm glad she made us if the alternative is making nothing.|j},
  ),
  Speech(
    Kaxig,
    {j|just can't help but wish she'd kept making us for a lil bit longer.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|battery's almost empty. we're out of time.|j}),
  Speech(
    Kaxig,
    {j|hey, uh. if you see her out there somewhere, tell her something for me, will ya? tell her, next time...|j},
  ),
  SpeechAndEndGame(Kaxig, {j|next time she should let it last longer.|j}),
  GoToScript(endScript),
];
