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

    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-parameter"

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
        collision_matrix[EntityProfiles::Id::PLAYER][EntityProfiles::Id::MYSTERY_BOX] = 
        [](Entity& player, const Entity& box, Direction direction, Queue<Event>& event_queue) -> void {
            if (direction == Direction::UP) {
                event_queue.push(Event(CondemnEntityEvent(box.id)));
                event_queue.push(Event(ConceiveEntityEvent(EntityConfiguration(
                    EntityState(
                        box.state.position
                            + box.profile->dimensions/2
                            - EntityProfiles::get()[EntityProfiles::Id::MUSHROOM].dimensions/2,
                        Vec2<int>(0, -240),
                        Vec2<int>(0, 0)
                    ),
                    EntityProfiles::Id::MUSHROOM,
                    nullptr
                ))));
            }
        };
        

        return collision_matrix;
    }

    #pragma GCC diagnostic pop
}