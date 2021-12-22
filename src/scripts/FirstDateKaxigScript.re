open Script;

let endScript: list(event) = [];

let rec script: list(Script.event) = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Excited),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, {j|i'm about to take you somewhere fucked up. let's go!|j}),
  TransitionBackground(Arcade),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Excited),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, {j|this is a deep-fried arcade!!|j}),
  ExpressionChange(Kolme, Embarrassed),
  Speech(Kolme, {j|Wh...!? Help!?|j}),
  ExpressionChange(Yksi, Anxious),
  Speech(Yksi, {j|A bit garish for a first date, perhaps...|j}),
  ExpressionChange(Kaxig, Excited),
  Speech(
    Kaxig,
    {j|nah bud. dating is all about being noisy and grainy and washed-out like hell.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(Kaxig, {j|so, player. whatcha think?|j}),
  Choice([|
    {text: "It's lovely", result: loveItScript},
    {text: "I hate it here", result: hateItScript},
  |]),
]
and loveItScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(
    Kaxig,
    {j|what!? ah, dangit. i was hoping you'd think it sucked ass.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|yeah, well. there'll be more opportunities for ass-sucking later. let's just keep going.|j},
  ),
  GoToScript(askAboutKaxigScript),
]
and hateItScript = [
  ExpressionChange(Kaxig, Excited),
  Speech(Kaxig, {j|yes... ha ha ha... YES!|j}),
  Speech(
    Kaxig,
    {j|see, now you already kinda hate this date a little. and that's good, see?|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|these other two chumps think you're supposed to start out being nice to each other, lmao.|j},
  ),
  Speech(
    Kaxig,
    {j|nah, i'm on that next-level shit. ENEMIES TO LOVERS, that's how we do dating.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|That's fair, actually. The only trope better than enemies to lovers is lovers to enemies.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|we'll do that one afterwards if there's time. anyway...|j},
  ),
  GoToScript(askAboutKaxigScript),
]
and askAboutKaxigScript = [
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kaxig,
    {j|so we're on a date, right. aren't you gonna try to get to know me?|j},
  ),
  Speech(Kaxig, {j|come on, ask me anythin.|j}),
  Choice([|
    {text: "How would you describe yourself?", result: describeSelfScript},
    {
      text: "What do you like about the deep-fried arcade?",
      result: whyDeepFriedScript,
    },
    {text: "What are some of your interests?", result: interestsScript},
  |]),
]
and describeSelfScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|how would i describe myself?|j}),
  Speech(Kaxig, {j|i'm a horrid cave gremlin. i live in a dumpster.|j}),
  Speech(Kaxig, {j|i keep a rancid cheese in my fridge as a little pet.|j}),
  Speech(
    Kaxig,
    {j|i bark like a wild dog at old ladies who pass me on the street.|j},
  ),
  Speech(
    Kaxig,
    {j|when i eat chocolate bars i just chew right through the entire wrapper.|j},
  ),
  Speech(
    Kaxig,
    {j|my favorite drink is vodka with a single scrabble tile in the glass. any letter.|j},
  ),
  Speech(Kaxig, {j|i wear all-denim outfits on public transport.|j}),
  Speech(Kaxig, {j|does that answer your question??|j}),
  Choice([|
    {text: "Yes", result: answeredQuestionScript},
    {text: "No", result: didNotAnswerQuestionScript},
    {text: "You're just like me", result: justLikeMeScript},
  |]),
]
and answeredQuestionScript = [
  Speech(
    Kaxig,
    {j|cool. then you can't say you didn't know what you were getting into later.|j},
  ),
  GoToScript(nextDateScript),
]
and didNotAnswerQuestionScript = [
  Speech(Kaxig, {j|yeah, that tracks. only REAL GOBLINS will get it.|j}),
  GoToScript(nextDateScript),
]
and justLikeMeScript = [
  Speech(Kaxig, {j|lol. i *highly* doubt that.|j}),
  Speech(
    Kaxig,
    {j|i had to invent this personality from scratch, cause the fucker who made us didn't give me one.|j},
  ),
  Speech(
    Kaxig,
    {j|so my vibes? they are ALL original character, do not steal.|j},
  ),
  ExpressionChange(Kaxig, Excited),
  Speech(
    Kaxig,
    {j|but hey... you can bark like a wild dog too if ya want. ;)|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  GoToScript(nextDateScript),
]
and whyDeepFriedScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(Kaxig, {j|i mean, it kinda rules, right?|j}),
  Speech(
    Kaxig,
    {j|look at this place. full of fucked up shapes and colors.|j},
  ),
  Speech(
    Kaxig,
    {j|there's an inflated watermark, there's a warped arcade machine monster, there's eyes in the static.|j},
  ),
  Speech(
    Kaxig,
    {j|i love shit like that. i wanna be someplace where everything feels like it has an unspecified clown illness.|j},
  ),
  GoToScript(nextDateScript),
]
and interestsScript = [
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|Actually, none of us really have "interests"... our creator didn't -|j},
  ),
  ExpressionChange(Kolme, Surprised),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|ok, calm down, let me answer it.|j}),
  Speech(Kolme, {j|Oh! Y-yes, of course!|j}),
  ExpressionChange(Kolme, Neutral),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|my interests, yeah. i like video games, and i like, uh...|j},
  ),
  ExpressionChange(Kaxig, Anxious),
  Speech(Kaxig, {j|...|j}),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|in my spare time, i like to, uh, squish all the bubbles out from under poorly applied screen protectors. yeah.|j},
  ),
  GoToScript(nextDateScript),
]
and nextDateScript = [
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|anyway, let's do something together, yeah? i have an idea.|j},
  ),
  ExpressionChange(Kaxig, Excited),
  Speech(
    Kaxig,
    {j|you and me, we're gonna play a ttrpg together. you know, a roleplaying game.|j},
  ),
  ExpressionChange(Kaxig, Neutral),
  Speech(
    Kaxig,
    {j|i haven't had anybody to play with since, uh... well, for a REAL long time.|j},
  ),
  Speech(Kaxig, {j|so, you wanna play a game or what?|j}),
  Choice([|
    {text: "Sure", result: PlayGameWithKaxigScript.script},
    {
      text: "I'd rather do something else",
      result: DontPlayWithKaxigScript.script,
    },
    {text: "Why not play with Yksi and Kolme?", result: whyNotPlayScript},
  |]),
]
and whyNotPlayScript = [
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|...|j}),
  Speech(Kaxig, {j|hey, other selves. you wanna play a ttrpg with me?|j}),
  ExpressionChange(Yksi, Excited),
  Speech(
    Yksi,
    {j|Oh, I could certainly try! Though I frequently find myself more interested in the sort of metafictional aspects of it.|j},
  ),
  ExpressionChange(Yksi, Neutral),
  Speech(
    Yksi,
    {j|There's a certain sense in which collaborative storytelling is, ipso facto, an experience on the order of -|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|yep. and you, lil guy?|j}),
  ExpressionChange(Kolme, Surprised),
  Speech(
    Kolme,
    {j|Oh, um, I'd like to help you have fun! But I get so anxious making my character, I don't know!|j},
  ),
  ExpressionChange(Kolme, Anxious),
  Speech(
    Kolme,
    {j|They give you a sheet and you have to pick a name? And stats? How do I know if I have "intelligence" or "charisma"?|j},
  ),
  ExpressionChange(Kaxig, Angry),
  Speech(Kaxig, {j|... you see what i'm dealing with?|j}),
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Kaxig,
    {j|so, let's just you and me play a game, and these bozos can hang around.|j},
  ),
  Choice([|
    {text: "Sure", result: PlayGameWithKaxigScript.script},
    {
      text: "I'd rather do something else",
      result: DontPlayWithKaxigScript.script,
    },
  |]),
];
