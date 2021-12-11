open Script;

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
  ExpressionChange(Yksi, Neutral),
  ExpressionChange(Kaxig, Neutral),
  ExpressionChange(Kolme, Neutral),
  Speech(
    Yksi,
    {j|... Well, I always say, it's only a crime if you get caught.|j},
  ),
  GoToScript(script),
];
