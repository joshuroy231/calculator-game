#include "entities-impl.hpp"
#include "keypad.hpp"

#include <debug.h>

Keypad keypad = Keypad();

void controlImpl(Entity* entity) {
    ButtonState* button_states = entity->control.controller->getButtonStates();
    Velocity target_velocity = Velocity(0,0);
    if (button_states[UP] == HIGH || button_states[UP] == RISING_EDGE) {
        target_velocity.y -= 5;
    }
    if (button_states[DOWN] == HIGH || button_states[DOWN] == RISING_EDGE) {
        target_velocity.y += 5;
    }
    if (button_states[LEFT] == HIGH || button_states[LEFT] == RISING_EDGE) {
        target_velocity.x -= 5;
    }
    if (button_states[RIGHT] == HIGH || button_states[RIGHT] == RISING_EDGE) {
        target_velocity.x += 5;
    }
    dbg_printf("Target velocity: (%d, %d)\n", target_velocity.x, target_velocity.y);
    entity->target_velocity = target_velocity;
}

EntityConfiguration player = {
    Position(0, 0),
    Dimensions(16, 16),
    Velocity(10, 10),
    Velocity(0, 0),
    Color(255),
    Control(&keypad, controlImpl),
    true,
    true,
    true
};

const int num_entities = 1;