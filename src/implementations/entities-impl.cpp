#include "entities-impl.hpp"
#include "keypad.hpp"

#include <debug.h>

Keypad keypad = Keypad();

void controlImpl(Entity* entity) {
    ButtonState* button_states = entity->entity_profile->control.controller->getButtonStates();
    int target_velocity_x = 0;
    if (button_states[LEFT] == HIGH || button_states[LEFT] == RISING_EDGE) {
        target_velocity_x -= entity->entity_profile->walking_target_velocity;
    }
    if (button_states[RIGHT] == HIGH || button_states[RIGHT] == RISING_EDGE) {
        target_velocity_x += entity->entity_profile->walking_target_velocity;
    }
    if (button_states[UP] == RISING_EDGE) {
        entity->velocity.y = -192;
    }
    entity->target_velocity.x = target_velocity_x;
}

EntityProfile player_profile = EntityProfile(
    Dimensions(16, 16),
    Color(RED),
    Control(&keypad, controlImpl),
    512,
    160,
    true,
    true,
    true
);

EntityConfiguration player_configuration = EntityConfiguration(
    Position(32, 32),
    Velocity(0, 0),
    Velocity(0, 320),
    &player_profile
);
EntityConfiguration player2_configuration = EntityConfiguration(
    Position(96, 96),
    Velocity(0, 0),
    Velocity(0, 40),
    &player_profile
);

const int num_entities = 1;
EntityConfiguration entities[num_entities] = {
    player_configuration,
};