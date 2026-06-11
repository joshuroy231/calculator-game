#pragma once

#include "systems/system.hpp"
#include "events/event.hpp"
#include "utilities/queue.hpp"
#include "on-collision-function.hpp"
#include "utilities/matrix.hpp"


class EntityCollisionSystem : public System {
    private:
        Matrix<OnCollisionFunction>& collision_matrix;
    public:
        EntityCollisionSystem(
            Entity* entity_registry,
            int* num_entities,
            Queue<Event>* event_queue,
            Matrix<OnCollisionFunction>& collision_matrix
        )
        : System(entity_registry, num_entities, event_queue)
        , collision_matrix(collision_matrix) {}
        void update() override;
};