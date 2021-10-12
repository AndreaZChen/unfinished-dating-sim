let getSceneById: string => (module Interfaces.Scene) =
  id =>
    switch (id) {
    | id when id == InitialScene.Scene.id => (module InitialScene.Scene)
    | _unknownId => (module InitialScene.Scene)
    };
