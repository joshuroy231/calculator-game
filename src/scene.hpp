#pragma once

#include "entities/entity-profile.hpp"
#include "tilemap.hpp"
#include "cameras/camera.hpp"

class Scene {
    public:
        int entity_pool_size;
        EntityConfiguration* initial_entities;
        int num_initial_entities;
        Tilemap tilemap;
        Color background_color;
        Camera camera;
        Vec2<int> gravity;
        Scene(
            int entity_pool_size,
            EntityConfiguration* initial_entities,
            int num_initial_entities,
            Tilemap tilemap,
            Color background_color,
            Camera camera,
            Vec2<int> gravity
        )
        : entity_pool_size(entity_pool_size)
        , initial_entities(initial_entities)
        , num_initial_entities(num_initial_entities)
        , tilemap(tilemap)
        , background_color(background_color)
        , camera(camera)
        , gravity(gravity)
        {}
};
