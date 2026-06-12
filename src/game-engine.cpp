#include <tice.h>
#include <debug.h>
#include <sys/util.h>

#include "game-engine.hpp"

GameEngine::GameEngine(Game* game, FixedVector<System*>& systems)
    : event_queue(256)
    , entity_manager(
        game->entity_pool_size,
        game->entity_profiles,
        event_queue
    )
    , game(game)
    , systems(systems)
    {
        for (System* s : systems) {
            s->init(
                entity_manager.entity_registry,
                &entity_manager.num_entities,
                &event_queue
            );
        }
    }

void GameEngine::registerKeypad(Keypad* keypad) {
    this->keypad = keypad;
}

void GameEngine::playGame() {
    for (System* system : systems) {
        system->initGame(game);
    }
    playScene(game->scene);
    dbg_printf("Exiting playGame...\n");
}
void GameEngine::playScene(Scene* scene) {
    for (System* system : systems) {
        system->initScene(scene);
    }
    for (int i = 0; i < scene->num_initial_entities; i++) {
        entity_manager.conceiveEntity(scene->initial_entities[i]);
    }
    timer_Enable(1, TIMER_32K, TIMER_NOINT, TIMER_UP);
    event_queue.push(Event(MainEntityEvent(entity_manager.entity_registry[0].id)));
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
    timer_Disable(1);
    dbg_printf("Exiting playScene...\n");
}