#include "entities-impl.hpp"
#include "keypad.hpp"
#include "actuators/standard-actuator.hpp"
#include "utilities/enum-map.hpp"

#include <debug.h>

Keypad keypad = Keypad();

StandardActuator actuator = StandardActuator();

enum class EntityProfileId {
    PLAYER,
    MYSTERY_BOX,

    COUNT
};

EnumMap<EntityProfileId, EntityProfile> entity_profiles;

entity_profiles[EntityProfileId::PLAYER] = EntityProfile(
    Vec2<int>(12, 16),
    Color(RED),
    Control(&keypad, &actuator),
    1536,
    160,
    320,
    Vec2<int>(0, -256),
    true,
    true,
    true,
    true
);
entity_profiles[EntityProfileId::MYSTERY_BOX] = EntityProfile(
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

EntityState player_initial_state = EntityState(
    Vec2<int>(32, 128),
    Vec2<int>(0, 0),
    Vec2<int>(0, 0)
);
EntityState mystery_box_initial_state = EntityState(
    Vec2<int>(32, 32),
    Vec2<int>(),
    Vec2<int>()
);

EntityConfiguration entities[] = {
    EntityConfiguration(
        player_initial_state,
        &entity_profiles[EntityProfileId::PLAYER]
    ),
    EntityConfiguration(
        mystery_box_initial_state,
        &entity_profiles[EntityProfileId::MYSTERY_BOX]
    )
};
const int num_entities = 2;