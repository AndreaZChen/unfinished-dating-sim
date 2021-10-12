type t('a) = {
  id: string,
  backgroundImage: option(string),
  title: string,
  yksiExpression: Character.yksiExpression,
  kaxigExpression: Character.kaxigExpression,
  kolmeExpression: Character.kolmeExpression,
  text: string,
  getNextScene: 'a => t('a),
};

let make =
    (
      ~backgroundImage=?,
      ~title=?,
      ~yksiExpression=?,
      ~kaxigExpression=?,
      ~kolmeExpression=?,
      ~text=?,
      ~id,
      ~getNextScene,
      previousScene: t('a),
    ) => {
  id,
  backgroundImage:
    Belt.Option.getWithDefault(
      backgroundImage,
      previousScene.backgroundImage,
    ),
  title: Belt.Option.getWithDefault(title, previousScene.title),
  yksiExpression:
    Belt.Option.getWithDefault(yksiExpression, previousScene.yksiExpression),
  kaxigExpression:
    Belt.Option.getWithDefault(
      kaxigExpression,
      previousScene.kaxigExpression,
    ),
  kolmeExpression:
    Belt.Option.getWithDefault(
      kolmeExpression,
      previousScene.kolmeExpression,
    ),
  text: Belt.Option.getWithDefault(text, previousScene.text),
  getNextScene,
};
