#pragma once

#include "system.hpp"
#include "entities/entity.hpp"
#include "tilemap.hpp"

class PhysicsSystem : System {
    private:
        Tilemap* tilemap;
    public:
        PhysicsSystem(Entity* entity_registry, int const& num_entities, Tilemap* tilemap);
        void update() override;
};