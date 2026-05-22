#pragma once

#include <stdint.h>
#include "device-properties.hpp"
#include "entities/entity-profile.hpp"

#define TILE_PIXELS 16

class Tilemap {
    private:
        int num_cols = SCREEN_WIDTH_PIXELS/TILE_PIXELS;
        int num_rows = SCREEN_HEIGHT_PIXELS/TILE_PIXELS;
    public:
        uint8_t* data;

        Tilemap();
        Tilemap(uint8_t* data)
        : data(data) {}
        uint8_t at(int col, int row);
};

class Scene {
    public:
        int entity_pool_size;
        EntityConfiguration* initial_entities;
        int num_initial_entities;
        Tilemap tilemap;
        Scene(
            int entity_pool_size,
            EntityConfiguration* initial_entities,
            int num_initial_entities,
            Tilemap tilemap
        )
        : entity_pool_size(entity_pool_size)
        , initial_entities(initial_entities)
        , num_initial_entities(num_initial_entities)
        , tilemap(tilemap)
        {}
};
class Game {
    public:
        Scene* scene;
        Game(Scene* scene)
        : scene(scene) {}
};