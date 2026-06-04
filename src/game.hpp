#pragma once

#include "scene.hpp"

class Game {
    public:
        Scene* scene;
        EntityProfile* entity_profiles;
        Game(
            Scene* scene,
            EntityProfile* entity_profiles
        )
        : scene(scene)
        , entity_profiles(entity_profiles) {}
};