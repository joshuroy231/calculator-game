#include "games/test-game/definitions/on-collision-functions.hpp"

#include "games/test-game/definitions/entity-profiles.hpp"

namespace OnCollisionFunctions {
    CollisionMatrix& init();
    CollisionMatrix& get() {
        static CollisionMatrix& collision_matrix = init();
        return collision_matrix;
    }
    CollisionMatrix& init() {
        static CollisionMatrix collision_matrix;
        for (int i = 0; i < EntityProfiles::Id::COUNT; i++) {
            for (int j = 0; j < EntityProfiles::Id::COUNT; j++) {
                collision_matrix[i][j] = nullptr;
            }
        }

        collision_matrix[EntityProfiles::Id::PLAYER][EntityProfiles::Id::GOOMBA] = 
        [](Entity& player, const Entity& goomba, Queue<Event>& event_queue) -> void {
            event_queue.push(Event(CondemnEntityEvent(player.id)));
        };
        return collision_matrix;
    }
}