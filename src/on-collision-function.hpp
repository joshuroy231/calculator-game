#pragma once

#include "entities/entity.hpp"
#include "utilities/queue.hpp"
#include "events/event.hpp"

enum class Direction {
    UP,
    DOWN,
    RIGHT,
    LEFT,
};

using OnCollisionFunction = void(*)(Entity&, const Entity&, Direction direction, Queue<Event>&);