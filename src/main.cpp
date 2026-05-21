#include <stdint.h>

#include "keypad.hpp"
#include "entity-manager.hpp"
#include "game-engine.hpp"
#include "game.hpp"

void controlImpl(Entity* entity) {
    if (entity->control.controller->getButtonState(UP) == HIGH) {
        entity->target_velocity.x = 5;
    }
}
int main() {
    EntityConfiguration player = EntityConfiguration();
    player.has_rendering = true;
    player.has_physics = true;
    player.has_control = true;
    player.position = Position(100, 100);
    player.dimensions = Dimensions(16, 16);
    player.color = Color(1);
    Keypad keypad = Keypad();
    player.control = Control(&keypad, controlImpl);

    Scene scene = Scene(1, &player, 1);
    Game game = Game(&scene);
    GameEngine engine = GameEngine(&game);
    engine.playGame();
}