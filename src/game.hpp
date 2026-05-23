#pragma once

#include "scene.hpp"

class Game {
    public:
        Scene* scene;
        Game(Scene* scene)
        : scene(scene) {}
};