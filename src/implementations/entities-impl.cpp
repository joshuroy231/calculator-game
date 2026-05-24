#include "entities-impl.hpp"
#include "keypad.hpp"
#include "actuators/standard-actuator.hpp"

#include <debug.h>

Keypad keypad = Keypad();

StandardActuator actuator = StandardActuator(160, 256);

EntityProfile player_profile = EntityProfile(
    Dimensions(16, 16),
    Color(RED),
    Control(&keypad, &actuator),
    512,
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