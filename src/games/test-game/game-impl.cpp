#include "games/test-game/game-impl.hpp"
#include "games/test-game/scenes.hpp"
#include "games/test-game/definitions/entity-profiles.hpp"
#include "games/test-game/definitions/on-collision-functions.hpp"

namespace Games {
    Game* get() {
        static Game* test_game = new Game(
            Scenes::get(),
            EntityProfiles::get(),
            OnCollisionFunctions::get(),
            32
        );
        return test_game;
    }
    void free() {
        Game* game = get();
        delete game;
    }
}