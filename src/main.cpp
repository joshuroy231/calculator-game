#include "game-engine.hpp"
#include "game.hpp"

#include "implementations/game-impl.hpp"

int main() {
    GameEngine engine = GameEngine(&game);
    engine.playGame();
}