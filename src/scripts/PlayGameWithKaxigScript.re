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
and suplexScript = [GoToScript(postRpgScript)]
and runAwayScript = [GoToScript(postRpgScript)]
and charmScript = [GoToScript(postRpgScript)]
and postRpgScript = [];
