#include "game.hpp"
#include "entities/entity-manager.hpp"
#include "entities-impl.hpp"
#include "tilemap-impl.hpp"

Scene* scene = new Scene(
    num_entities,
    entities,
    num_entities,
    tilemap,
    Color(LIGHT_BLUE)
);

Game game = Game(scene);