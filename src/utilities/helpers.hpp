#pragma once

#include "utilities/vec2.hpp"
#include "utilities/box.hpp"

bool areColliding(Box<int> box1, Box<int> box2) {
    if (box1.x_max < box2.x_min) return false;
    if (box1.x_min > box2.x_max) return false;
    if (box1.y_max < box2.y_min) return false;
    if (box1.y_min > box2.y_max) return false;
    return true;
}

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

Vec2<int> getCollision(Box<int> box1, Vec2<int> v1, Box<int> box2, Vec2<int> v2) {
    Vec2<int> overlap;
    overlap.x = (box2.x_min + box2.x_max - box1.x_min - box1.x_max > 0)
    ? box2.x_min - box1.x_max
    : box2.x_max - box1.x_min;
    overlap.y = (box2.y_min + box2.y_max - box1.y_min - box1.y_max > 0)
    ? box2.y_min - box1.y_max
    : box2.y_max - box1.y_min;
    
    Vec2<int> relative_velocity = v2 - v1;
    int x_weight = abs(overlap.y * relative_velocity.x);
    int y_weight = abs(overlap.x * relative_velocity.y);

    if (y_weight > x_weight && overlap.y*relative_velocity.y >= 0) {
        return Vec2(0, overlap.y);
    }
    else if (overlap.x*relative_velocity.x >= 0) {
        return Vec2(overlap.x, 0);
    }
    else return Vec2<int>(0,0);
}