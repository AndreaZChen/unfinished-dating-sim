type t =
  | Yksi
  | Kaxig
  | Kolme;

type expression =
  | Neutral
  | Embarrassed
  | Surprised
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
    | (Yksi, Neutral | Embarrassed | Anxious | Excited | Angry | Surprised) => "yksi_neutral.png"
    | (Yksi, Deactivated) => "yksi_deactivated.png"
    | (Kaxig, Neutral | Embarrassed | Anxious | Excited | Angry | Surprised) => "kaxig_neutral.png"
    | (Kaxig, Deactivated) => "kaxig_deactivated.png"
    | (Kolme, Neutral | Angry) => "kolme_neutral.png"
    | (Kolme, Deactivated) => "kolme_deactivated.png"
    | (Kolme, Embarrassed | Surprised) => "kolme_embarrassed.png"
    | (Kolme, Anxious) => "kolme_anxious.png"
    | (Kolme, Excited) => "kolme_excited.png"
    }
  );
