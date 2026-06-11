#include "game-engine.hpp"
#include "game.hpp"

#include "games/test-game/game-impl.hpp"
#include "games/test-game/definitions/systems.hpp"
#include "keypad.hpp"

int main() {
    GameEngine engine = GameEngine(Games::get(), Systems::get());
    engine.registerKeypad(getStandardKeypad());
    engine.playGame();
}