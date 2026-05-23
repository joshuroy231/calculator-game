#pragma once

#include "system.hpp"
#include "entities/entity.hpp"

class ControlSystem : System {
    public:
        ControlSystem(Entity* entity_registry, int const& num_entities);
        void update() override;
};