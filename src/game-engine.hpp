#pragma once

#include "entities/entity-manager.hpp"
#include "systems/system.hpp"
#include "keypad.hpp"
#include "utilities/queue.hpp"
#include "utilities/fixed-vector.hpp"
#include "events/event.hpp"
#include "game.hpp"
 
class GameEngine {
    private:
        size_t frame_counter = 0;

        Queue<Event> event_queue;

        EntityManager entity_manager;

        Game* game;

        FixedVector<System*> systems;

        Keypad* keypad;

        void playScene(Scene* scene);
    public:
        GameEngine(Game* game, FixedVector<System*> systems);
        void registerKeypad(Keypad* keypad);
        void playGame();
};