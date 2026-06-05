#pragma once

#include "systems/system.hpp"
#include "events/event.hpp"
#include "utilities/queue.hpp"
#include "on-collision-function.hpp"
#include "utilities/matrix.hpp"


class EntityCollisionSystem : public System {
    private:
        Matrix<OnCollisionFunction>& collision_matrix;
        Queue<Event>& event_queue;
    public:
        EntityCollisionSystem(
            Entity* entity_registry,
            Matrix<OnCollisionFunction>& collision_matrix,
            Queue<Event>& event_queue,
            const int& num_entities
        )
        : System(entity_registry, num_entities)
        , collision_matrix(collision_matrix)
        , event_queue(event_queue) {}
        void update() override;
};