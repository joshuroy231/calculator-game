#pragma once

#include "utilities/vec2.hpp"

bool areColliding(Vec2<int> box_1_position, Vec2<int> box_1_dimensions,
    Vec2<int> box_2_position, Vec2<int> box_2_dimensions) {
    if (box_1_position.x >= box_2_position.x + box_2_dimensions.x) return false;
    if (box_1_position.y >= box_2_position.y + box_2_dimensions.y) return false;
    if (box_1_position.x + box_1_dimensions.x <= box_2_position.x) return false;
    if (box_1_position.y + box_1_dimensions.y <= box_2_position.y) return false;
    return true;
}

int abs(int n) {
    return (n < 0) ? -n : n;
}