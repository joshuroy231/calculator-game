#pragma once

#include "components.hpp"

class Entity {
    Position* position = nullptr;
    Dimensions* dimensions = nullptr;
    Velocity* velocity = nullptr;
    Velocity* target_velocity = nullptr;
    Color* color = nullptr;
    Entity() = default;
    class Builder {
        Position position;
        Dimensions dimensions;
        Velocity velocity;
        Velocity target_velocity;
        Color color;
    };
};