#include "games/test-game/game-impl.hpp"
#include "games/test-game/scene-impl.hpp"

namespace Games {
    Game* get() {
        static Game* test_game = new Game(Scenes::get());
        return test_game;
    }
}