#include <stdint.h>

#include "keypad.hpp"
#include "entity-manager.hpp"
#include "game-engine.hpp"
#include "game.hpp"
#include "implementations/tilemap-impl.hpp"
#include "implementations/entities-impl.hpp"

int main() {
    Scene scene = Scene(
        1,
        &player,
        1,
        tilemap
    );

    Game game = Game(&scene);
    GameEngine engine = GameEngine(&game);
    engine.playGame();
}