#pragma once

#include "systems/system.hpp"

class EntityCollisionSystem : public System {
    public:
        EntityCollisionSystem(Entity* entity_registry, const int& num_entities)
        : System(entity_registry, num_entities) {}
        void update() override;
};