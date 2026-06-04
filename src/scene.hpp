#pragma once

#include "entities/entity-configuration.hpp"
#include "tilemap.hpp"
#include "cameras/camera.hpp"

class Scene {
    public:
        EntityConfiguration* initial_entities;
        int num_initial_entities;
        Tilemap tilemap;
        uint8_t background_color;
        Camera camera;
        Vec2<int> gravity;
        Vec2<int> dimensions_pixels;
        Scene(
            EntityConfiguration* initial_entities,
            int num_initial_entities,
            Tilemap tilemap,
            uint8_t background_color,
            Camera camera,
            Vec2<int> gravity
        )
        : initial_entities(initial_entities)
        , num_initial_entities(num_initial_entities)
        , tilemap(tilemap)
        , background_color(background_color)
        , camera(camera)
        , gravity(gravity)
        , dimensions_pixels(tilemap.tile_dimensions * TILE_PIXELS)
        {}
};
