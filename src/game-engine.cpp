#include <tice.h>
#include <debug.h>

#include "game-engine.hpp"

GameEngine::GameEngine(Game* game)
    : entity_manager(game->scene->entity_pool_size)
    , rendering_system(
        entity_manager.entity_registry,
        entity_manager.num_entities,
        &game->scene->tilemap,
        game->scene->background_color,
        game->scene->camera.getPosition()
    )
    , physics_system(entity_manager.entity_registry, entity_manager.num_entities, &game->scene->tilemap, game->scene->gravity)
    , control_system(entity_manager.entity_registry, entity_manager.num_entities)
    , entity_collision_system(entity_manager.entity_registry, entity_manager.num_entities)
    , game(game)
    {}

void GameEngine::registerKeypad(Keypad* keypad) {
    this->keypad = keypad;
}

void GameEngine::playGame() {
    playScene(game->scene);
}
void GameEngine::playScene(Scene* scene) {
    for (int i = 0; i < scene->num_initial_entities; i++) {
        entity_manager.conceiveEntity(scene->initial_entities[i]);
    }
    timer_Enable(1, TIMER_32K, TIMER_NOINT, TIMER_UP);

    while (true) {
        uint32_t start = timer_Get(1);

        entity_manager.updateEntities();
        if (keypad != nullptr) {
            keypad->scan();
            if (keypad->getButtonState(QUIT) == RISING_EDGE) break;
        }

        control_system.update();
        physics_system.update();
        entity_collision_system.update();
        rendering_system.update();

        uint32_t end = timer_Get(1);
        uint32_t processing_time = (end - start)/32;

        if (processing_time < 32) delay(32 - processing_time);
    }
}