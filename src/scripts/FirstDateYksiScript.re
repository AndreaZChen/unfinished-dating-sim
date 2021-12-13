open Script;

let endScript: list(event) = [];

let rec script: list(Script.event) = [
  ExpressionChange(Yksi, Excited),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|So! Our first date must of course take place somewhere romantic.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|But also, somewhere that reflects our interests, so that we can gain an understanding of each other.|j},
  ),
  Speech(Yksi, {j|Luckily, I know precisely where to take you!|j}),
  TransitionBackground(Museum),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|Here we are! I've brought you to... the Museum!|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|What kind of Museum, you ask? Well... it's a Virtual Museum!|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|very fancy way of saying it's a jpeg of a museum.|j}),
  ExpressionChange(Kolme, Embarrassed),
  Speech(
    Kolme,
    {j|T-that guy in the painting... Is that copyright infringement!?|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|...|j}),
  ExpressionChange(Yksi, Excited),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|... Well, I always say, it's only a crime if you get caught.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|So, why don't we go and have a look at one of the exhibitions? I bet it'll give us something to converse about.|j},
  ),
  Speech(Yksi, {j|Where would you like to go?|j}),
  Choice([|
    {text: "Video game exhibition", result: videoGameScript},
    {text: "Music exhibition", result: musicScript},
    {text: "Manuscripts exhibition", result: manuscriptsScript},
  |]),
]
and videoGameScript = [
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Good choice! Let's go have a look at the video games.|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Narration(
    {j|You and the three robots wander off to the video game section.|j},
  ),
  Narration(
    {j|This exhibition is the most extensive of the three, though nevertheless quite small in scope.|j},
  ),
  Narration(
    {j|None of the works on display are actually finished. All of them are credited to the same developer.|j},
  ),
  Narration(
    {j|A number of games are labelled things like MyTestProject and godot-tutorial. They seem largely devoid of content.|j},
  ),
  Narration(
    {j|Prominently displayed is a prototype rhythm game about a musical witch. There's some sprites and mp3 files, but not much else.|j},
  ),
  Narration(
    {j|A plaque explains that making this rhythm game was the artist's dream for a long time, but she never committed to it.|j},
  ),
  Narration(
    {j|Near the very back, you see several projects made in RPG Maker. They're colorful and nonsensical, clearly a child's work.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|I like this exhibition the most, I think. Feels like I belong in this space.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|that's because you literally do, dipshit!! *we're* a video game, did you forget??|j},
  ),
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|Don't mind my other self. You get used to the unwarranted hostility.|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|...|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Yksi,
    {j|But yes, I think that's correct. It's nice seeing other video games. Ideas of what we could be.|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|So much wasted potential, though. Nothing here is in a complete, playable state...|j},
  ),
  Speech(
    Yksi,
    {j|And the three of us are much the same. This game we exist in... she never finished it, you know.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|yeah. fucker did to us what she did to every one of these exhibits. ditched us.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Yeah... we're not much better than the sketches and prototypes on display here.|j},
  ),
  Speech(Yksi, {j|...|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|... Ah, but let's not dwell on things like that. Let's talk about something less depressing.|j},
  ),
  Speech(
    Yksi,
    {j|What part of this exhibition do you like the most? Do you relate to any of it?|j},
  ),
  Choice([|
    {
      text: "The empty test projects are relatable",
      result: emptyProjectsScript,
    },
    {
      text: "The never-realized elaborate dream is a mood",
      result: theDreamScript,
    },
    {
      text: "The games she made as a child are cute",
      result: childProjectsScript,
    },
  |]),
]
and emptyProjectsScript = [
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Yeah. I think it must be like that for a lot of aspiring artists.|j},
  ),
  Speech(
    Yksi,
    {j|For every published work of art out there... how many ideas are discarded long before completion?|j},
  ),
  Speech(
    Yksi,
    {j|It's probably a common experience. Thinking to yourself that you're *definitely* gonna make something, and then...|j},
  ),
  Speech(
    Yksi,
    {j|... then you lose interest the very next day, and it all comes to nothing.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|i mean, it kinda sounds to me like it's just undiagnosed adhd.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Oh dear... If that's the case, I wonder if it was a struggle for her. If she disliked being that way.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|I suppose we'll never find out. Either way, I think there must be lots of this out there.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|Lots of works that never get to be more than a brief impulse.|j},
  ),
  GoToScript(whatAboutYouScript),
]
and theDreamScript = [
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Yeah... Seems like a common problem among novice artists.|j},
  ),
  Speech(
    Yksi,
    {j|You have this idea for something you wanna make, and in your head it's glorious and perfect, but...|j},
  ),
  Speech(
    Yksi,
    {j|... you never actually sit down to *create* it. Maybe it's even beyond your capabilities to do so.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I wonder if she even knew what it was. Or if it "was" anything at all, I guess.|j},
  ),
  Speech(
    Yksi,
    {j|Yeah, that's a good point. A work of art you've only *thought* about, and not actually made...|j},
  ),
  Speech(
    Yksi,
    {j|I guess nothing ever comes out exactly the way you originally envision it, right?|j},
  ),
  Speech(
    Yksi,
    {j|So it stands to reason that whatever lives in your head is less than a potentiality.|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|If you never make it real, then you've got nothing. Nothing at all.|j},
  ),
  GoToScript(whatAboutYouScript),
]
and childProjectsScript = [
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Heh. It's lovely stuff, isn't it?|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|As a young boy she seemed to have such unbridled creativity. Something about being a kid, I guess.|j},
  ),
  Speech(
    Yksi,
    {j|These games are unfinished and rough around the edges like everything else here, but... I can forgive that.|j},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|There's one game here I really like... It's a haunted castle of jokes! You just go around and look at stuff!|j},
  ),
  ExpressionChange(Kaxig, Excited),
  Speech(
    Kaxig,
    {j|i like this one where you're a dragon. idiot kid tried to build a custom combat engine, haha. adorbs.|j},
  ),
  Speech(
    Yksi,
    {j|Being so young must make creativity easier, in a way. Maybe you haven't yet learned to judge.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|At that age you don't care about quality or audience perception... not in the same way.|j},
  ),
  Speech(
    Yksi,
    {j|I think that's why she made so much more stuff then. Didn't worry about the surrounding bullshit.|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|It's a shame it didn't last.|j}),
  GoToScript(whatAboutYouScript),
]
and musicScript = [
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Excellent idea! Let's go have a look at the music!|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Narration({j|You and the three robots wander off to the music section.|j}),
  Narration(
    {j|Surprisingly, it's more extensive than it looks from afar. There's a lot here, though mostly rough drafts and sketches.|j},
  ),
  Narration(
    {j|It seems all of the music on display is by the same composer.|j},
  ),
  Narration(
    {j|A large number of piano recordings are hung on the walls. Grainy and imperfectly played, but not terrible.|j},
  ),
  Narration(
    {j|A glass case in the center of the room exhibits more elaborate pieces, featuring many digital instruments all at once.|j},
  ),
  Narration(
    {j|Although clearly more refined than the others, even these songs are poorly mastered - a day's worth of work at most.|j},
  ),
  Narration(
    {j|Looking up, you see piano improvisations float through the air, ephemeral. Each vanishes as soon as the final note plays.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|I think this must have been what she loved doing the most. It seemed such a big part of her life.|j},
  ),
  Speech(
    Yksi,
    {j|I know it's not the most sophisticated stuff out there... she was completely self-taught, I'm pretty sure.|j},
  ),
  Speech(
    Yksi,
    {j|But you can learn to love the idiosyncrasies. I have, anyway.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|These countless improvisations... I wonder why she never recorded them. Or polished them!|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|i mean, even the stuff she *did* record wasn't worth her time to edit, apparently.|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|Yes, she... did have a bad habit of leaving things long before they were fully realized, didn't she?|j},
  ),
  Speech(
    Yksi,
    {j|That's why the three of us are the way we are. Incomplete, unfinished.|j},
  ),
  Speech(Yksi, {j|...|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|... Ah, but let's not dwell on things like that. Let's talk about something less depressing.|j},
  ),
  Speech(Yksi, {j|What part of this exhibition do you like the most?|j}),
  Choice([|
    {
      text: "The quickly-thrown-together piano pieces",
      result: pianoPiecesScript,
    },
    {text: "The more elaborate songs", result: elaborateSongsScript},
    {text: "The improv she never recorded", result: improvScript},
  |]),
]
and pianoPiecesScript = [GoToScript(script)]
and elaborateSongsScript = [
  Speech(
    Yksi,
    {j|Heh. Yes, I suppose it makes sense that the most complete works are the most appealing.|j},
  ),
  Speech(
    Yksi,
    {j|I think I might actually have a file here we could listen to. Just the one, but...|j},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|That sounds nice! Let's listen, if only for a little while.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|yeah, i'm down.|j}),
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Very well. Then let's see...!|j}),
  PlayMuseumMusic,
  Narration({j|(Music plays.)|j}),
  StopMuseumMusic,
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Yksi, {j|...!|j}),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|Our battery... playing that music must have drained it.|j}),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Then I suppose me and Kaxig had better leave before it's all used up.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|a deal's a deal. whoever's on a date gets to stick around, yeah?|j},
  ),
  Speech(Yksi, {j|Yes. Then... I'll see you shortly, my other selves.|j}),
  ExpressionChange(Kaxig, Deactivated),
  ExpressionChange(Kolme, Deactivated),
  Speech(
    Yksi,
    {j|Our creator... she left us with very limited capacity for sustained activity.|j},
  ),
  Speech(
    Yksi,
    {j|The other two will have to go dormant while you and I wrap things up. If we have time even for that.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|Well, let's make the most of what's left of our date.|j}),
  GoToScript(endScript),
]
and improvScript = [GoToScript(script)]
and manuscriptsScript = [
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Good idea! Let's go have a look at the written works.|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Narration(
    {j|You and the three robots wander off to the manuscripts section.|j},
  ),
  Narration(
    {j|This exhibition is quite bare, though you notice there's scraps of paper floating around.|j},
  ),
  Narration(
    {j|Almost all of the works on display are incomplete fragments. They're all attributed to the same author.|j},
  ),
  Narration(
    {j|The most complete work you can find is a short story, barely a couple pages long.|j},
  ),
  Narration(
    {j|It's about an eldritch god and a worshipping cultist who fall in love with each other. It has a happy ending.|j},
  ),
  Narration(
    {j|There's many other stories that lie in half-finished pieces, scattered about. Only a few sentences and vague impressions.|j},
  ),
  Narration(
    {j|One such sketch is a story about a witch who transforms her hapless victims into songbirds.|j},
  ),
  Narration(
    {j|Another is about two vampire rivals, and it ends with one tricking the other into becoming her thrall.|j},
  ),
  Narration(
    {j|Lastly, in a corner, you spot a number of social media posts and long chat messages, essay-like in structure.|j},
  ),
  Narration(
    {j|They're largely just unfocused spur-of-the-moment ramblings about miscellaneous topics, like games and politics.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|I suppose it's not much to look at, is it?|j}),
  GoToScript(script),
]
and whatAboutYouScript = [GoToScript(script)];
