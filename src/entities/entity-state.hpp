#pragma once

#include "utilities/vec2.hpp"

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