#pragma once

#include "components.hpp"
#include "utilities/vec2.hpp"

struct EntityProfile {
    const Vec2<int> dimensions;
    const Color color;

    const int terminal_velocity_x = 0;
    const int terminal_velocity_y = 0;

    const bool has_rendering = false;
    const bool has_physics = false;
    const bool has_control = false;
    const bool has_collision = false;
    EntityProfile() = default;
    EntityProfile(
        Vec2<int> dimensions,
        Color color,
        int terminal_velocity_x,
        int terminal_velocity_y,
        bool has_rendering,
        bool has_physics,
        bool has_control,
        bool has_collision
    )
    : dimensions(dimensions)
    , color(color)
    , terminal_velocity_x(terminal_velocity_x)
    , terminal_velocity_y(terminal_velocity_y)
    , has_rendering(has_rendering)
    , has_physics(has_physics)
    , has_control(has_control)
    , has_collision(has_collision) {}
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
    Actuator* actuator;
    EntityConfiguration(
        const EntityState initial_state,
        const EntityProfile* profile,
        Actuator* actuator
    )
    : initial_state(initial_state)
    , profile(profile)
    , actuator(actuator) {}
};