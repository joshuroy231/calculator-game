#pragma once

#include <debug.h>

#include "utilities/vec2.hpp"
#include "utilities/box.hpp"

bool areColliding(Box<int> box1, Box<int> box2);

int abs(int n);

Vec2<int> getCollision(Box<int> box1, Vec2<int> v1, Box<int> box2, Vec2<int> v2);