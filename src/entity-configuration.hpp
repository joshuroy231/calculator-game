#pragma once

#include "components.hpp"

struct EntityConfiguration {
        Position position;
        Dimensions dimensions;
        Velocity velocity;
        Velocity target_velocity;
        Color color;
        Control control;
        bool has_rendering = false;
        bool has_physics = false;
        bool has_control = false;
};