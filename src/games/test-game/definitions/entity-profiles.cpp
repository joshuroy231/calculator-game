#include "games/test-game/definitions/entity-profiles.hpp"
#include "games/test-game/definitions/actuators.hpp"
#include "keypad.hpp"

namespace EntityProfiles {
    EntityProfile* get(EntityProfileId id) {
        switch (id) {
            case EntityProfileId::PLAYER:
                static EntityProfile* player = new EntityProfile(
                    Vec2<int>(12, 16),
                    Color(RED),
                    Control(getStandardKeypad(), Actuators::get()),
                    1536,
                    160,
                    320,
                    Vec2<int>(0, -256),
                    true,
                    true,
                    true,
                    true
                );
                return player;
            case EntityProfileId::MYSTERY_BOX:
                static EntityProfile* box = new EntityProfile(
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
                return box;
            default:
                return nullptr;
        }
    }
}