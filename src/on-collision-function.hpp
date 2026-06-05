#pragma once

#include "entities/entity.hpp"
#include "utilities/queue.hpp"
#include "events/event.hpp"

using OnCollisionFunction = void(*)(Entity&, const Entity&, Queue<Event>&);