#pragma once

#include "components.hpp"
#include "device-properties.hpp"

class Camera {
    protected:
        Position position;
    public:
        const Position& getPosition() { return position; }
        void setPosition(const Position position) { this->position = position; }
        Camera(Position initial_position)
        : position(initial_position) {}
};