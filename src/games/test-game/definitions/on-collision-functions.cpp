#include "games/test-game/definitions/on-collision-functions.hpp"

#include "games/test-game/definitions/entity-profiles.hpp"

namespace OnCollisionFunctions {
    OnCollisionFunction* get() {
    }
    OnCollisionFunction[EntityProfiles::Id::COUNT][EntityProfiles::Id::COUNT]& init() {
        static OnCollisionFunction matrix[EntityProfiles::Id::COUNT][EntityProfiles::Id::COUNT];
        for (int i = 0; i < EntityProfiles::Id::COUNT; i++) {
            for (int j = 0; j < EntityProfiles::Id::COUNT; j++) {
                matrix[i][j] = nullptr;
            }
        }

        matrix[EntityProfiles::Id::PLAYER][EntityProfiles::Id::GOOMBA] = [](Entity& player, const Entity& goomba) -> void {

        };
        return matrix;
    }
}