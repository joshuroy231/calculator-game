#include <stdint.h>

#include "entity-manager.hpp"
#include "game-engine.hpp"
#include "game.hpp"

class DumbController : public Controller {
    ButtonState getButtonState(Button button) override {
        if (button == RIGHT) return ON;
        else return OFF;
    }
};

void controlImpl(Entity* entity) {
    if (entity->control.controller->getButtonState(RIGHT) == ON) {
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
    DumbController dumb_controller = DumbController();
    player.control = Control(&dumb_controller, controlImpl);

    Scene scene = Scene(1, &player, 1);
    Game game = Game(&scene);
    GameEngine engine = GameEngine(&game);
    engine.playGame();
}