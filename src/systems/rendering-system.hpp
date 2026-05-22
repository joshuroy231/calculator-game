#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "system.hpp"
#include "components.hpp"
#include "entities/entity-manager.hpp"
#include "game.hpp"

class RenderingSystem : System {
    private:
        Tilemap* tilemap;
    public:
        RenderingSystem(
            Entity* entity_registry,
            int const& num_entities,
            Tilemap* tilemap
        );
        ~RenderingSystem();
        void update() override;
        void renderBackground();
        void renderTiles();
        void renderEntities();
};