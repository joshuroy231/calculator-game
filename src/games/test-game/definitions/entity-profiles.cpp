#include "games/test-game/definitions/entity-profiles.hpp"
#include "games/test-game/definitions/actuators.hpp"
#include "keypad.hpp"

namespace EntityProfiles {
    const EntityProfile player = EntityProfile(
        Vec2<int>(12, 16),
        Color(RED),
        Control(&standard_keypad, &Actuators::actuator),
        1536,
        160,
        320,
        Vec2<int>(0, -256),
        true,
        true,
        true,
        true
    );
    const EntityProfile mystery_box = EntityProfile(
        Vec2<int>(32, 32),
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
}