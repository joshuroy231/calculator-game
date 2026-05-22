#include "game-engine.hpp"

GameEngine::GameEngine(Game* game)
    : entity_manager(game->scene->entity_pool_size)
    , rendering_system(entity_manager.entity_registry, entity_manager.num_entities, &game->scene->tilemap)
    , physics_system(entity_manager.entity_registry, entity_manager.num_entities) {}

void GameEngine::playGame() {
    playScene(game->scene);
}
void GameEngine::playScene(Scene* scene) {
    for (int i = 0; i < scene->num_initial_entities; i++) {
        entity_manager.conceiveEntity(scene->initial_entities[i]);
    }
    while (true) {
        entity_manager.updateEntities();

        physics_system.update();
        rendering_system.update();
    }
}