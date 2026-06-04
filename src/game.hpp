#pragma once

#include "scene.hpp"

class Game {
    public:
        Scene* scene;
        EntityProfile* entity_profiles;
        int entity_pool_size;
        Game(
            Scene* scene,
            EntityProfile* entity_profiles,
            int entity_pool_size
        )
        : scene(scene)
        , entity_profiles(entity_profiles)
        , entity_pool_size(entity_pool_size) {}
};