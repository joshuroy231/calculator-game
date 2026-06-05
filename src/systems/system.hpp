#pragma once

#include "entities/entity.hpp"
#include "utilities/queue.hpp"
#include "events/event.hpp"

class System {
    protected:
        Entity* entity_registry;
        int const& num_entities;
        Queue<Event>& event_queue;
        System(
            Entity* entity_registry,
            int const& num_entities,
            Queue<Event>& event_queue
        )
        : entity_registry(entity_registry)
        , num_entities(num_entities)
        , event_queue(event_queue) {}
    public:
        virtual void update() = 0;
};