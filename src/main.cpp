#include "game-engine.hpp"
#include "game.hpp"

#include "games/test-game/game-impl.hpp"
#include "keypad.hpp"

int main() {
    GameEngine engine = GameEngine(Games::get());
    engine.registerKeypad(getStandardKeypad());
    engine.playGame();
}