#include "game-engine.hpp"

Gamesystem::Gamesystem(Game* game)
    : entity_manager(game->scene->entity_pool_size)
    , rendering_system(entity_manager.entity_registry, entity_manager.num_entities)
    , physics_system(entity_manager.entity_registry, entity_manager.num_entities) {}

void Gamesystem::playGame() {
    playScene(game->scene);
}
void Gamesystem::playScene(Scene* scene) {
    for (int i = 0; i < scene->num_initial_entities; i++) {
        entity_manager.conceiveEntity(scene->initial_entities[i]);
    }
    while (true) {
        entity_manager.updateEntities();

        physics_system.simulate();
        rendering_system.render();
    }
}