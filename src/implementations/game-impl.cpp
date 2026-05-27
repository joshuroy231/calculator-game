#include "game.hpp"
#include "entities/entity-manager.hpp"
#include "entities-impl.hpp"
#include "tilemap-impl.hpp"
#include "cameras/camera.hpp"

Scene* scene = new Scene(
    32,
    entities,
    num_entities,
    tilemap,
    Color(LIGHT_BLUE),
    Camera(Vec2<int>(0,0)),
    Vec2<int>(0, 512)
);

Game game = Game(scene);