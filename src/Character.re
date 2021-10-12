type t =
  | Yksi
  | Kaxig
  | Kolme;

type yksiExpression =
  | Neutral;

type kaxigExpression =
  | Neutral;

type kolmeExpression =
  | Neutral
  | Embarrassed;

let charactersFolder = "../assets/characters/";

let getKolmeImage = kolmeExpression =>
  charactersFolder
  ++ (
    switch (kolmeExpression) {
    | Neutral => "kolme_neutral.png"
    | Embarrassed => "kolme_embarrassed.png"
    }
  );
