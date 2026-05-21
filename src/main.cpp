#include <stdint.h>

#include "keypad.hpp"
#include "entity-manager.hpp"
#include "game-engine.hpp"
#include "game.hpp"

void controlImpl(Entity* entity) {
    ButtonState* button_states = entity->control.controller->getButtonStates();
    Velocity target_velocity = Velocity(0,0);
    if (button_states[UP] == HIGH || button_states[UP] == RISING_EDGE) {
        target_velocity.x -= 5;
    }
    if (button_states[DOWN] == HIGH || button_states[DOWN] == RISING_EDGE) {
        target_velocity.x += 5;
    }
    if (button_states[LEFT] == HIGH || button_states[LEFT] == RISING_EDGE) {
        target_velocity.x -= 5;
    }
    if (button_states[RIGHT] == HIGH || button_states[RIGHT] == RISING_EDGE) {
        target_velocity.x += 5;
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