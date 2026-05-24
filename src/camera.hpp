#pragma once

#include "components.hpp"
#include "device-properties.hpp"

class Camera {
    private:
    public:
        const Dimensions dimensions = Dimensions(SCREEN_WIDTH_PIXELS, SCREEN_HEIGHT_PIXELS);
        Position position;
        Camera(Position initial_position)
        : position(initial_position) {}
};