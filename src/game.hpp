#pragma once

#include "entity-configuration.hpp"

class Tilemap {
    private:
        int num_cols = 20;
        int num_rows = 15;
        uint8_t* data;
    public:
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