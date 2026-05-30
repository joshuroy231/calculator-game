#pragma once

#include "vec2.hpp"

template<typename T>
class Box {
    public:
        T x_min;
        T y_min;
        T x_max;
        T y_max;
        Box(
            T x_min,
            T y_min,
            T x_max,
            T y_max
        )
        : x_min(x_min)
        , y_min(y_min)
        , x_max(x_max)
        , y_max(y_max) {}
        Box(Vec2<T> position, Vec2<T> dimensions) {
            x_min = position.x;
            y_min = position.y;
            x_max = position.x + dimensions.x;
            y_max = position.y + dimensions.y;
        }
};