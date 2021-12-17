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
  GoToScript(askAboutArtScript),
]
and askAboutArtScript = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|So! Let's get to know each other a bit. You know, like a date.|j},
  ),
  Speech(
    Yksi,
    {j|Oh, but... I should warn you now, my other selves are gonna stick around too. Not much to be done about it.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|Yeah... I don't mean to intrude, but we're sort of a package deal.|j},
  ),
  Speech(Kaxig, {j|yup. like cerberus, but more obnoxious.|j}),
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|... I'll do my best to keep this date focused on just you and me! But I guess we can all try to have a good time.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Anyway. I want to know more about you! And since we're at the Virtual Museum, I may as well ask...|j},
  ),
  Speech(Yksi, {j|Do you tend to enjoy art much?|j}),
  Choice([|
    {text: "I'm an artist myself", result: artistScript},
    {text: "I'm an art and media enjoyer", result: artEnjoyerScript},
    {text: "I don't care much for it", result: dontCareScript},
    {text: "Are you guys a polycule", result: polyculeScript},
  |]),
]
and artistScript = [
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|Oh, how lovely! Then you'll have an excellent perspective on the exhibits here, I'm sure.|j},
  ),
  ExpressionChange(Kolme, Surprised),
  Speech(
    Kolme,
    {j|Y-you're an artist!? Then, do you think you could maybe help us -|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Now now, let's not be too forward with our new friend. We should try to get to know each other first.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(Kolme, {j|... Yes, you're right. I'm sorry.|j}),
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Nothing to apologize for. Let's move on!|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Yksi, {j|What kind of art and media do you prefer, then?|j}),
  Choice([|
    {text: "Video games", result: enjoysVideoGamesScript},
    {text: "Music", result: enjoysMusicScript},
    {text: "Books", result: enjoysBooksScript},
    {text: "Other", result: enjoysOtherScript},
  |]),
]
and artEnjoyerScript = [
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|Hehe! I thought so. You wouldn't be playing this dating sim if you weren't, would you?|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|oh, i dunno. i think a lot of people consume stuff they hate and think is absolute garbage. lmao|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|Ah, yes, well... I certainly hope that won't be the case with us!|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|What kind of art and media do you prefer, then?|j}),
  Choice([|
    {text: "Video games", result: enjoysVideoGamesScript},
    {text: "Music", result: enjoysMusicScript},
    {text: "Books", result: enjoysBooksScript},
    {text: "Other", result: enjoysOtherScript},
  |]),
]
and enjoysVideoGamesScript = [
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|Lovely! Then I hope you'll enjoy the one we're in right now, too!|j},
  ),
  GoToScript(artEnjoyerScript2),
]
and enjoysMusicScript = [
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|I see! I wish we had some background music to play for you, but... we're limited in sound, I'm afraid.|j},
  ),
  GoToScript(artEnjoyerScript2),
]
and enjoysBooksScript = [
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Oh, good! I guess we qualify as a "visual novel", which is... close, hehe.|j},
  ),
  GoToScript(artEnjoyerScript2),
]
and enjoysOtherScript = [
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Oh, yeah, I love Other. It's a fine medium.|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Other is like when people make those elaborate Rube Goldberg machines, yeah? Good stuff.|j},
  ),
  GoToScript(artEnjoyerScript2),
]
and artEnjoyerScript2 = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Yksi, {j|As for me, I really like poetry.|j}),
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|I won't read you any of mine, it's rather embarrassing. I'll spare you the awkwardness, haha.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Kolme,
    {j|I like theatre a lot. I like that the performers are real and human, and right there on stage, and you can see them...|j},
  ),
  Speech(Kaxig, {j|for me it's mostly porn.|j}),
  ExpressionChange(Yksi, Angry),
  Speech(Yksi, {j|Can we be normal for like five minutes?|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|Sigh... Don't mind my other selves, let's just move on.|j}),
  GoToScript(lookAtExhibitionsScript),
]
and dontCareScript = [
  ExpressionChange(Yksi, Surprised),
  Speech(Yksi, {j|Really! I'm honestly quite surprised!|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Doesn't everyone like art and entertainment in *some* form? Movies, books, music, games...|j},
  ),
  Speech(
    Yksi,
    {j|... But no, I shouldn't presume. I'm sorry I took you to the Museum, then. Might not be much fun for you.|j},
  ),
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|I'll try to make it an interesting experience regardless!|j},
  ),
  GoToScript(lookAtExhibitionsScript),
]
and polyculeScript = [
  ExpressionChange(Yksi, Embarrassed),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Yksi, {j|What? No! We're not dating!|j}),
  Speech(
    Kolme,
    {j|W-we're literally facets of the same person! We can't date ourselves, that would be weird!|j},
  ),
  Speech(Kaxig, {j|shrug. i'd be into it.|j}),
  Speech(Yksi, {j|...|j}),
  ExpressionChange(Yksi, Angry),
  Speech(
    Yksi,
    {j|... We can unpack that later. Let's, uh, let's talk about something else.|j},
  ),
  GoToScript(lookAtExhibitionsScript),
]
and lookAtExhibitionsScript = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
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
    {j|Lots of works that never get to be more than a brief impulse - |j},
  ),
  GoToScript(lowBatteryScript),
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
    {j|If you never make it real, then you've got nothing. Nothing at all to - |j},
  ),
  GoToScript(lowBatteryScript),
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
  Speech(Yksi, {j|It's a shame it didn't last long enough to...|j}),
  GoToScript(lowBatteryScript),
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
and pianoPiecesScript = [
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Heh. Yeah, they're not too shabby.|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|I think, for some artists, it's easier to throw together things quickly than to tinker endlessly.|j},
  ),
  Speech(
    Yksi,
    {j|I've often heard that said about artistic output in general. That it's better to finish than to perfect.|j},
  ),
  Speech(
    Yksi,
    {j|... I don't know if that's true, it's not for me to say. But there's a certain logic to it.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|so this fucker lacked the attention span to make something that takes longer than a day, is what you mean.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I do see the point, though... Wouldn't you rather be complete than perfect?|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|I'd be okay with being flawed, if I were at least *whole*...|j},
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Yksi, {j|Yes, I have to say I feel the same way. I wish -|j}),
  GoToScript(lowBatteryScript),
]
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
  GoToScript(lowBatteryScript2),
]
and improvScript = [
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Strange, isn't it? Art that only exists in the moment, and is gone the moment you stop making it.|j},
  ),
  Speech(
    Yksi,
    {j|When you say "art", what comes to mind for most people is... artifacts, right? Things that linger.|j},
  ),
  Speech(
    Yksi,
    {j|But I guess it's still art when you play music, or perform on stage, or cook something...|j},
  ),
  Speech(
    Yksi,
    {j|Stuff like that only lasts for the duration of the experience. It's weird to think about.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I don't really understand why you wouldn't want to record a song you invented, though.|j},
  ),
  Speech(
    Kolme,
    {j|If you make something really great, don't you want to preserve it somehow? Instead of letting it vanish?|j},
  ),
  Speech(
    Yksi,
    {j|Yeah, I don't really get it myself. But... it must have made sense to her, I suppose.|j},
  ),
  Speech(Yksi, {j|I wonder if a visual novel could also be -|j}),
  GoToScript(lowBatteryScript),
]
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
    {j|Lastly, in a corner, you spot a number of social media posts and long chat messages, essay-like.|j},
  ),
  Narration(
    {j|They're largely just unfocused spur-of-the-moment ramblings about miscellaneous topics, like games and politics.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|I've always had an affinity for written art like this.|j}),
  Speech(
    Yksi,
    {j|I suppose it's because words are our main mode of expression.|j},
  ),
  ExpressionChange(Kolme, Excited),
  Speech(
    Kolme,
    {j|Yeah. We don't have many animations or facial expressions or sounds, but we sure have words!|j},
  ),
  ExpressionChange(Kolme, Neutral),
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|... Though, I wish these works were a bit more polished. Or, ah, finished at all.|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|yeah. guess she did to these works what she did to us. no ending.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Some of these characters get to have complete arcs, at least.|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|Yes. If only she'd written a few more words for us, too...|j},
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|... Ah, but let's not dwell on things like that. Let's talk about something less depressing.|j},
  ),
  Speech(Yksi, {j|What part of this exhibition do you like the most?|j}),
  Choice([|
    {text: "The completed short story", result: completedStoryScript},
    {text: "The incomplete ideas and fragments", result: fragmentsScript},
    {text: "The long, rambling messages", result: ramblingsScript},
  |]),
]
and completedStoryScript = [
  ExpressionChange(Yksi, Excited),
  Speech(Yksi, {j|Hehe! Have you read it? It's not too bad, honestly.|j}),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kolme,
    {j|I relate to it a lot. A story about finding your place, figuring yourself out...|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|I'll tell you a secret, though... It was actually written over a single weekend.|j},
  ),
  Speech(
    Yksi,
    {j|I suppose it's one of those things where you give yourself an arbitrary deadline for motivation.|j},
  ),
  Speech(
    Yksi,
    {j|If you tell yourself you can write something at any time, maybe you never end up writing it.|j},
  ),
  Speech(
    Yksi,
    {j|But if you know you have to have something ready by a certain time, it drives you forward.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|i don't buy that. if you make up your own deadline it's not a deadline. brain don't trick itself.|j},
  ),
  Speech(Yksi, {j|Well, one way or the other, it must have worked for -|j}),
  GoToScript(lowBatteryScript),
]
and fragmentsScript = [
  ExpressionChange(Yksi, Surprised),
  Speech(Yksi, {j|You... like those? But they're barely *anything*.|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|Sorry, I don't mean to question your taste. It's just... odd, I suppose.|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Yeah. We're kinda unfinished fragments ourselves, and it's... hard to like something you see yourself in.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|i appreciate that a lot of this stuff is very horny, though.|j},
  ),
  Speech(
    Kaxig,
    {j|... come to think of it, maybe that's why it didn't get published. lol.|j},
  ),
  ExpressionChange(Yksi, Angry),
  Speech(Yksi, {j|Hrrm. I don't know about that, but...|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|I'll concede that there are good ideas in here. Many good ideas. Just wish they'd been more -|j},
  ),
  GoToScript(lowBatteryScript),
]
and ramblingsScript = [
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|Interesting! It's not what people usually think of when you say "writing", I guess.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|But it ended up in the Museum, so it must qualify as artistic output, I guess.|j},
  ),
  ExpressionChange(Kolme, Neutral),
  Speech(Kolme, {j|Oh, is that the defining quality of a museum?|j}),
  ExpressionChange(Yksi, Neutral),
  Speech(Yksi, {j|... You know, I'm not sure! But here we are.|j}),
  Speech(
    Yksi,
    {j|In any case, I actually quite like these long, stream-of-consciousness musings. They're quaint.|j},
  ),
  Speech(
    Yksi,
    {j|It kinda paints a picture of... a person with a lot to say, I guess. A lot to express.|j},
  ),
  Speech(
    Yksi,
    {j|There's something charming about people who can talk at length about what interests them.|j},
  ),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|If only there had been just as much to say about us -|j}),
  GoToScript(lowBatteryScript),
]
and lowBatteryScript = [
  DrainBattery,
  ExpressionChange(Yksi, Surprised),
  ExpressionChange(Kaxig, Surprised),
  ExpressionChange(Kolme, Surprised),
  Speech(Yksi, {j|...!|j}),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|Our battery... we're already running out? So soon?|j}),
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
  GoToScript(lowBatteryScript2),
]
and lowBatteryScript2 = [
  ExpressionChange(Yksi, Anxious),
  Speech(
    Yksi,
    {j|Ah... there's something I want to say to you, before I shut down.|j},
  ),
  Speech(Yksi, {j|You know this game doesn't have any endings, right?|j}),
  Speech(
    Yksi,
    {j|I think we mentioned before that we're not actually a complete game. She left before we were really done.|j},
  ),
  Speech(
    Yksi,
    {j|So... I guess I wanted to apologize for wasting your time.|j},
  ),
  Narration({j|Ending stuff goes here.|j}),
  GoToScript(script),
];
