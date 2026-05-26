#include "entities-impl.hpp"
#include "keypad.hpp"
#include "actuators/standard-actuator.hpp"

#include <debug.h>

Keypad keypad = Keypad();

StandardActuator actuator = StandardActuator();

EntityProfile player_profile = EntityProfile(
    Vec2<int>(16, 16),
    Color(RED),
    Control(&keypad, &actuator),
    512,
    160,
    320,
    Vec2<int>(0, -256),
    true,
    true,
    true
);
EntityState player_initial_state = EntityState(
    Vec2<int>(32, 32),
    Vec2<int>(0, 0),
    Vec2<int>(0, 0)
);

EntityConfiguration player_configuration = EntityConfiguration(
    player_initial_state,
    &player_profile
);

const int num_entities = 1;
EntityConfiguration entities[num_entities] = {
    player_configuration,
};