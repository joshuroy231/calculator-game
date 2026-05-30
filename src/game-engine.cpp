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
        game->scene->camera.position
    )
    , physics_system(entity_manager.entity_registry, entity_manager.num_entities, &game->scene->tilemap, game->scene->gravity)
    , control_system(entity_manager.entity_registry, entity_manager.num_entities)
    , entity_collision_system(entity_manager.entity_registry, entity_manager.num_entities)
    , camera_system(entity_manager.entity_registry, entity_manager.num_entities, game->scene->camera, game->scene->dimensions_pixels)
    , game(game)
    {}

void GameEngine::registerKeypad(Keypad* keypad) {
    this->keypad = keypad;
}

void GameEngine::playGame() {
    dbg_printf("Playing game\n");
    playScene(game->scene);
}
void GameEngine::playScene(Scene* scene) {
    dbg_printf("Playing scene\n");
    for (int i = 0; i < scene->num_initial_entities; i++) {
        entity_manager.conceiveEntity(scene->initial_entities[i]);
    }
    dbg_printf("Conceived entities\n");
    timer_Enable(1, TIMER_32K, TIMER_NOINT, TIMER_UP);
    camera_system.follow(&entity_manager.entity_registry[0]);

    while (true) {
        dbg_printf("Running\n");
        uint32_t start = timer_Get(1);

        entity_manager.updateEntities();
        dbg_printf("Updated entities\n");
        if (keypad != nullptr) {
            keypad->scan();
            if (keypad->getButtonState(Button::QUIT) == RISING_EDGE) break;
        }
        dbg_printf("Scanned keypad\n");
        if (keypad->getButtonState(Button::DEBUGS) == HIGH) {
            if (keypad->getButtonState(Button::UP) == RISING_EDGE) {
                entity_manager.condemnEntity(0);
            }
            if (keypad->getButtonState(Button::DOWN) == RISING_EDGE) {
                entity_manager.condemnEntity(1);
            }
        }
        dbg_printf("Scanned keypad again\n");

        control_system.update();
        dbg_printf("Did controls\n");
        physics_system.update();
        dbg_printf("Did physics\n");
        entity_collision_system.update();
        dbg_printf("Did collision\n");
        camera_system.update();
        dbg_printf("Did camera\n");
        rendering_system.update();
        dbg_printf("Did rendering\n");
        uint32_t end = timer_Get(1);
        uint32_t processing_time = (end - start)/32;

        if (processing_time < 32) delay(32 - processing_time);
    }
}