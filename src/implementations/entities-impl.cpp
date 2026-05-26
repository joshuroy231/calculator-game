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
    true,
    true
);
EntityProfile mystery_block_profile = EntityProfile(
    Vec2<int>(16, 16),
    Color(YELLOW),
    Control(),
    0,
    160,
    320,
    Vec2<int>(0, 0),
    true,
    true,
    false,
    true
);

EntityState player_initial_state = EntityState(
    Vec2<int>(32, 32),
    Vec2<int>(0, 0),
    Vec2<int>(0, 0)
);
EntityState mystery_box_initial_state = EntityState(
    Vec2<int>(128, 128),
    Vec2<int>(),
    Vec2<int>()
);

EntityConfiguration player_configuration = EntityConfiguration(
    player_initial_state,
    &player_profile
);

EntityConfiguration entities[] = {
    EntityConfiguration(
        player_initial_state,
        &player_profile
    ),
    EntityConfiguration(
        mystery_box_initial_state,
        &mystery_block_profile
    )
};
const int num_entities = 2;