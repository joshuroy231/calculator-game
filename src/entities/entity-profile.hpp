#pragma once

#include <stdint.h>
#include "utilities/vec2.hpp"
#include "collision-behavior.hpp"

struct EntityProfile {
    Vec2<int> dimensions;
    uint8_t color;

    int terminal_velocity_x;
    int terminal_velocity_y;

    bool has_rendering;
    bool has_physics;
    bool has_control;
    CollisionBehavior collision_behavior;
    EntityProfile() = default;
    EntityProfile(
        Vec2<int> dimensions,
        uint8_t color,
        int terminal_velocity_x,
        int terminal_velocity_y,
        bool has_rendering,
        bool has_physics,
        bool has_control,
        CollisionBehavior collision_behavior
    )
    : dimensions(dimensions)
    , color(color)
    , terminal_velocity_x(terminal_velocity_x)
    , terminal_velocity_y(terminal_velocity_y)
    , has_rendering(has_rendering)
    , has_physics(has_physics)
    , has_control(has_control)
    , collision_behavior(collision_behavior) {}
};