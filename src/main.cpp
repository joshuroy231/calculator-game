#include "game-engine.hpp"
#include "game.hpp"

#include "implementations/game-impl.hpp"
#include "implementations/entities-impl.hpp"

int main() {
    GameEngine engine = GameEngine(&game);
    engine.registerKeypad(&keypad);
    engine.playGame();
}