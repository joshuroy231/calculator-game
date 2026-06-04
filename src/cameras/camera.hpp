#pragma once

#include "components.hpp"
#include "device-properties.hpp"

class Camera {
    public:
        Vec2<int> dimensions;
        Vec2<int> position;
        Camera(Vec2<int> initial_position)
        : dimensions(Vec2<int>(SCREEN_WIDTH_PIXELS, SCREEN_HEIGHT_PIXELS))
        , position(initial_position) {}
};