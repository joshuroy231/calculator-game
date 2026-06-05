#pragma once

#include "entities/entity.hpp"
#include "utilities/queue.hpp"
#include "events/event.hpp"
#include "games/test-game/definitions/entity-profiles.hpp"

using OnCollisionFunction = void(*)(Entity&, const Entity&, Queue<Event>&);
using CollisionMatrix = OnCollisionFunction[EntityProfiles::Id::COUNT][EntityProfiles::Id::COUNT];

namespace OnCollisionFunctions {
    CollisionMatrix& get();
}