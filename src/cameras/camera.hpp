#pragma once

#include "components.hpp"
#include "device-properties.hpp"

class Camera {
    protected:
        Vec2<int> position;
    public:
        const Vec2<int>& getPosition() { return position; }
        void setPosition(const Vec2<int> position) { this->position = position; }
        Camera(Vec2<int> initial_position)
        : position(initial_position) {}
};