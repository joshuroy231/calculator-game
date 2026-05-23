#pragma once

#include "system.hpp"
#include "components.hpp"
#include "entities/entity-manager.hpp"
#include "game.hpp"

class PhysicsSystem : System {
    private:
        Tilemap* tilemap;
    public:
        PhysicsSystem(Entity* entity_registry, int const& num_entities, Tilemap* tilemap);
        void update() override;
};