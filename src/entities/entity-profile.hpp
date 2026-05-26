#pragma once

#include "components.hpp"
#include "utilities/vec2.hpp"

struct EntityProfile {
    const Vec2<int> dimensions;
    const Color color;
    const Control control;

    const int walking_acceleration;
    const int terminal_velocity_x;
    const int terminal_velocity_y;
    const Vec2<int> jumping_velocity;

    const bool has_rendering;
    const bool has_physics;
    const bool has_control;
    EntityProfile(
        Vec2<int> dimensions,
        Color color,
        Control control,
        int walking_acceleration,
        int terminal_velocity_x,
        int terminal_velocity_y,
        Vec2<int> jumping_velocity,
        bool has_rendering,
        bool has_physics,
        bool has_control
    )
    : dimensions(dimensions)
    , color(color)
    , control(control)
    , walking_acceleration(walking_acceleration)
    , terminal_velocity_x(terminal_velocity_x)
    , terminal_velocity_y(terminal_velocity_y)
    , jumping_velocity(jumping_velocity)
    , has_rendering(has_rendering)
    , has_physics(has_physics)
    , has_control(has_control) {}
};
struct EntityState {
    Vec2<int> position;
    Vec2<int> velocity;
    Vec2<int> acceleration;
    EntityState() = default;
    EntityState(
        Vec2<int> initial_position,
        Vec2<int> initial_velocity,
        Vec2<int> initial_acceleration
    )
    : position(initial_position)
    , velocity(initial_velocity)
    , acceleration(initial_acceleration) {}
};
struct EntityConfiguration {
    EntityState initial_state;
    const EntityProfile* profile;
    EntityConfiguration(
        EntityState initial_state,
        EntityProfile* profile
    )
    : initial_state(initial_state)
    , profile(profile) {}
};