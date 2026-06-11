#include <tice.h>
#include <debug.h>
#include <sys/util.h>

#include "game-engine.hpp"

GameEngine::GameEngine(Game* game)
    : event_queue(256)
    , entity_manager(
        game->entity_pool_size,
        game->entity_profiles,
        event_queue
    )
    , game(game)
    {
        systems[0] = new ControlSystem(
            entity_manager.entity_registry,
            entity_manager.num_entities,
            event_queue
        );
        systems[1] = new PhysicsSystem(
            entity_manager.entity_registry,
            entity_manager.num_entities,
            event_queue,
            &game->scene->tilemap,
            game->scene->gravity
        );
        systems[2] = new EntityCollisionSystem(
            entity_manager.entity_registry,
            entity_manager.num_entities,
            event_queue,
            game->collision_matrix
        );
        systems[3] = new CameraSystem(
            entity_manager.entity_registry,
            entity_manager.num_entities,
            event_queue,
            game->scene->camera,
            game->scene->dimensions_pixels
        );
        systems[4] = new RenderingSystem(
            entity_manager.entity_registry,
            entity_manager.num_entities,
            event_queue,
            &game->scene->tilemap,
            game->scene->background_color,
            game->scene->camera.position
        );
    }

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
    ((CameraSystem*)systems[4])->follow(&entity_manager.entity_registry[0]);
    frame_counter = 0;

    while (true) {
        uint32_t start = timer_Get(1);

        if (keypad != nullptr) {
            keypad->scan();
            if (keypad->getButtonState(Button::QUIT) == RISING_EDGE) break;
        }

        entity_manager.updateEntities();
        for (System* system : systems) system->update();
        entity_manager.consumeEvents();
        for (System* system : systems) system->consumeEvents();

        event_queue.flush();
        frame_counter++;

        uint32_t end = timer_Get(1);
        uint32_t processing_time = (end - start)/32;

        if (processing_time < 32) delay(32 - processing_time);
    }
}