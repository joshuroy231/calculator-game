#pragma once

#include "systems/system.hpp"
#include "events/event.hpp"
#include "utilities/queue.hpp"

using OnCollisionFunction = void(*)(Entity&, const Entity&, Queue<Event>&);

class EntityCollisionSystem : public System {
    public:
        EntityCollisionSystem(Entity* entity_registry, const int& num_entities)
        : System(entity_registry, num_entities) {}
        void update() override;
};