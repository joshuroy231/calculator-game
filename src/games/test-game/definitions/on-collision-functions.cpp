#include "games/test-game/definitions/on-collision-functions.hpp"

#include "games/test-game/definitions/entity-profiles.hpp"
#include "events/event.hpp"
#include "utilities/queue.hpp"

namespace OnCollisionFunctions {
    Matrix<OnCollisionFunction>& init();
    Matrix<OnCollisionFunction>& get() {
        static Matrix<OnCollisionFunction>& collision_matrix = init();
        return collision_matrix;
    }
    Matrix<OnCollisionFunction>& init() {
        static Matrix<OnCollisionFunction> collision_matrix(EntityProfiles::Id::COUNT, EntityProfiles::Id::COUNT);
        for (int i = 0; i < EntityProfiles::Id::COUNT; i++) {
            for (int j = 0; j < EntityProfiles::Id::COUNT; j++) {
                collision_matrix[i][j] = nullptr;
            }
        }

        collision_matrix[EntityProfiles::Id::PLAYER][EntityProfiles::Id::GOOMBA] = 
        [](Entity& player, const Entity& goomba, Direction direction, Queue<Event>& event_queue) -> void {
            if (direction == Direction::DOWN) {
                event_queue.push(Event(CondemnEntityEvent(goomba.id)));
            }
            else {
                event_queue.push(Event(CondemnEntityEvent(player.id)));
            }
        };
        return collision_matrix;
    }
}