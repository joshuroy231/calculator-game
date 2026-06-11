#pragma once

#include "system.hpp"
#include "entities/entity.hpp"
#include "tilemap.hpp"

class RenderingSystem : public System {
    private:
        Tilemap* tilemap;
        uint8_t background_color;
        Vec2<int>& camera_position;
    public:
        RenderingSystem(
            Entity* entity_registry,
            int* num_entities,
            Queue<Event>* event_queue,
            Tilemap* tilemap,
            uint8_t background_color,
            Vec2<int>& camera_position
        );
        ~RenderingSystem();
        void update() override;
        void renderBackground();
        void renderTiles();
        void renderEntities();
};