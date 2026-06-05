#pragma once

#include "system.hpp"
#include "entities/entity.hpp"

class ControlSystem : System {
    public:
        ControlSystem(
            Entity* entity_registry,
            int const& num_entities,
            Queue<Event>& event_queue
        );
        void update() override;
};