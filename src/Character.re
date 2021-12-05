type t =
  | Yksi
  | Kaxig
  | Kolme;

type expression =
  | Neutral
  | Embarrassed
  | Anxious
  | Excited
  | Angry
  | Deactivated;

let getName = character =>
  switch (character) {
  | Yksi => "Yksi"
  | Kaxig => "Kaxig"
  | Kolme => "Kolme"
  };

let charactersFolder = "assets/characters/";

let getImage = (character: t, expression: expression) =>
  charactersFolder
  ++ (
    switch (character, expression) {
    | (Yksi, Neutral | Embarrassed | Anxious | Excited | Angry | Deactivated) => "yksi_neutral.png"
    | (Kaxig, Neutral | Embarrassed | Anxious | Excited | Angry | Deactivated) => "kaxig_neutral.png"
    | (Kolme, Neutral | Angry | Deactivated) => "kolme_neutral.png"
    | (Kolme, Embarrassed) => "kolme_embarrassed.png"
    | (Kolme, Anxious) => "kolme_anxious.png"
    | (Kolme, Excited) => "kolme_excited.png"
    }
  );
