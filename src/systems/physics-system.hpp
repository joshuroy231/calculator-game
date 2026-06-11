#pragma once

#include "system.hpp"
#include "entities/entity.hpp"
#include "tilemap.hpp"

class PhysicsSystem : public System {
    private:
        Tilemap* tilemap;
        Vec2<int> gravity;
    public:
        PhysicsSystem(
            Entity* entity_registry,
            int* num_entities,
            Queue<Event>* event_queue,
            Tilemap* tilemap,
            Vec2<int> gravity
        );
        void update() override;
};