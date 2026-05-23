#include <tice.h>
#include <debug.h>

#include "game-engine.hpp"

GameEngine::GameEngine(Game* game)
    : entity_manager(game->scene->entity_pool_size)
    , rendering_system(entity_manager.entity_registry, entity_manager.num_entities, &game->scene->tilemap)
    , physics_system(entity_manager.entity_registry, entity_manager.num_entities, &game->scene->tilemap)
    , control_system(entity_manager.entity_registry, entity_manager.num_entities)
    , game(game)
    {}

void GameEngine::playGame() {
    dbg_printf("Num initial entities 6: %d\n", game->scene->num_initial_entities);
    playScene(game->scene);
}
void GameEngine::playScene(Scene* scene) {
    dbg_printf("Num initial entities 7: %d\n", scene->num_initial_entities);
    for (int i = 0; i < scene->num_initial_entities; i++) {
        entity_manager.conceiveEntity(scene->initial_entities[i]);
    }
    timer_Enable(1, TIMER_32K, TIMER_NOINT, TIMER_UP);

    while (true) {
        uint32_t start = timer_Get(1);

        entity_manager.updateEntities();

        control_system.update();
        physics_system.update();
        rendering_system.update();

        uint32_t end = timer_Get(1);
        uint32_t processing_time = (end - start)/32;

        if (processing_time < 30) delay(30 - processing_time);
    }
}