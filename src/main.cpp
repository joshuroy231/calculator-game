#include <stdint.h>
#include <debug.h>

#include "keypad.hpp"
#include "entities/entity-manager.hpp"
#include "game-engine.hpp"
#include "game.hpp"
#include "implementations/tilemap-impl.hpp"
#include "implementations/entities-impl.hpp"

int main() {
    dbg_printf("Num initial entities 1: %d\n", num_entities);
    Scene* scene = new Scene(
        num_entities,
        &player,
        num_entities,
        tilemap
    );
    dbg_printf("Num initial entities 2: %d\n", scene->num_initial_entities);

    Game* game = new Game(scene);
    dbg_printf("Num initial entities 3: %d\n", game->scene->num_initial_entities);
    GameEngine engine = GameEngine(game);
    engine.playGame();

    delete scene;
    delete game;
}