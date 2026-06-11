#pragma once

#include "entities/entity.hpp"
#include "utilities/queue.hpp"
#include "events/event.hpp"

class Game;
class Scene;

class System {
    protected:
        Entity* entity_registry = nullptr;
        int* num_entities = nullptr;
        Queue<Event>* event_queue = nullptr;
        System() = default;
    public:
        void init(Entity* entity_registry, int* num_entities, Queue<Event>* event_queue) {
            this->entity_registry = entity_registry;
            this->num_entities = num_entities;
            this->event_queue = event_queue;
        }
        virtual void update() = 0;
        virtual void consumeEvents() {};
        virtual void initGame(Game* game) {};
        virtual void initScene(Scene* scene) {};
};