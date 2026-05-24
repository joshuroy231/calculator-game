#pragma once

#include "system.hpp"
#include "entities/entity.hpp"
#include "tilemap.hpp"

class RenderingSystem : System {
    private:
        Tilemap* tilemap;
        Color background_color;
        const Position& camera_position;
    public:
        RenderingSystem(
            Entity* entity_registry,
            int const& num_entities,
            Tilemap* tilemap,
            Color background_color,
            const Position& camera_position
        );
        ~RenderingSystem();
        void update() override;
        void renderBackground();
        void renderTiles();
        void renderEntities();
};