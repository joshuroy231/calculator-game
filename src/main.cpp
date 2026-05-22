#include <stdint.h>

#include "keypad.hpp"
#include "entities/entity-manager.hpp"
#include "game-engine.hpp"
#include "game.hpp"
#include "implementations/tilemap-impl.hpp"
#include "implementations/entities-impl.hpp"

int main() {
    Scene scene = Scene(
        num_entities,
        entities,
        num_entities,
        tilemap
    );

    Game game = Game(&scene);
    GameEngine engine = GameEngine(&game);
    engine.playGame();
}