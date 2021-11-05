type t =
  | Yksi
  | Kaxig
  | Kolme;

type expression =
  | Neutral
  | Embarrassed
  | Anxious
  | Excited;

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
    | (Yksi, Neutral | Embarrassed | Anxious | Excited) => "yksi_neutral.png"
    | (Kaxig, Neutral | Embarrassed | Anxious | Excited) => "kaxig_neutral.png"
    | (Kolme, Neutral) => "kolme_neutral.png"
    | (Kolme, Embarrassed) => "kolme_embarrassed.png"
    | (Kolme, Anxious) => "kolme_anxious.png"
    | (Kolme, Excited) => "kolme_neutral.png"
    }
  );
