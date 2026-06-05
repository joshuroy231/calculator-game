#pragma once

#include "scene.hpp"
#include "on-collision-function.hpp"
#include "utilities/matrix.hpp"

class Game {
    public:
        Scene* scene;
        EntityProfile* entity_profiles;
        Matrix<OnCollisionFunction>& collision_matrix;
        int entity_pool_size;
        Game(
            Scene* scene,
            EntityProfile* entity_profiles,
            Matrix<OnCollisionFunction>& collision_matrix,
            int entity_pool_size
        )
        : scene(scene)
        , entity_profiles(entity_profiles)
        , collision_matrix(collision_matrix)
        , entity_pool_size(entity_pool_size) {}
};