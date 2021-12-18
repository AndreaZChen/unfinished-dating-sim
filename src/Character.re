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
    | (Yksi, Neutral) => "yksi_neutral.png"
    | (Yksi, Anxious) => "yksi_anxious.png"
    | (Yksi, Embarrassed | Surprised) => "yksi_surprised.png"
    | (Yksi, Angry) => "yksi_angry.png"
    | (Yksi, Excited) => "yksi_excited.png"
    | (Yksi, Deactivated) => "yksi_deactivated.png"
    | (Kaxig, Neutral) => "kaxig_neutral.png"
    | (Kaxig, Excited) => "kaxig_excited.png"
    | (Kaxig, Surprised) => "kaxig_surprised.png"
    | (Kaxig, Angry) => "kaxig_angry.png"
    | (Kaxig, Embarrassed | Anxious) => "kaxig_anxious.png"
    | (Kaxig, Deactivated) => "kaxig_deactivated.png"
    | (Kolme, Neutral | Angry) => "kolme_neutral.png"
    | (Kolme, Deactivated) => "kolme_deactivated.png"
    | (Kolme, Embarrassed | Surprised) => "kolme_embarrassed.png"
    | (Kolme, Anxious) => "kolme_anxious.png"
    | (Kolme, Excited) => "kolme_excited.png"
    }
  );
