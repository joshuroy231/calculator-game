#pragma once

#include "components.hpp"
#include "utilities/vec2.hpp"

struct EntityProfile {
    const Vec2<int> dimensions;
    const Color color;
    const Control control;

    const int walking_acceleration;

    const bool has_rendering;
    const bool has_physics;
    const bool has_control;
    EntityProfile(
        Vec2<int> dimensions,
        Color color,
        Control control,
        int walking_acceleration,
        bool has_rendering,
        bool has_physics,
        bool has_control
    )
    : dimensions(dimensions)
    , color(color)
    , control(control)
    , walking_acceleration(walking_acceleration)
    , has_rendering(has_rendering)
    , has_physics(has_physics)
    , has_control(has_control) {}
};
struct EntityConfiguration {
    const Vec2<int> initial_position;
    const Vec2<int> initial_velocity;
    const Vec2<int> initial_target_velocity;
    const EntityProfile* entity_profile;
    EntityConfiguration(
        Vec2<int> initial_position,
        Vec2<int> initial_velocity,
        Vec2<int> initial_target_velocity,
        EntityProfile* entity_profile
    )
    : initial_position(initial_position)
    , initial_velocity(initial_velocity)
    , initial_target_velocity(initial_target_velocity)
    , entity_profile(entity_profile) {}
};