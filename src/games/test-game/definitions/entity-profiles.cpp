#include "games/test-game/definitions/entity-profiles.hpp"
#include "games/test-game/definitions/actuators.hpp"
#include "keypad.hpp"

namespace EntityProfiles {
    EntityProfile* get(Id id) {
        switch (id) {
            case Id::PLAYER:
                static EntityProfile* player = new EntityProfile(
                    Vec2<int>(12, 16),
                    Color(RED),
                    160,
                    320,
                    true,
                    true,
                    true,
                    true
                );
                return player;
            case Id::MYSTERY_BOX:
                static EntityProfile* box = new EntityProfile(
                    Vec2<int>(32, 32),
                    Color(YELLOW),
                    160,
                    320,
                    true,
                    true,
                    false,
                    true
                );
                return box;
            case Id::GOOMBA:
                static EntityProfile* goomba = new EntityProfile(
                    Vec2<int>(16,16),
                    Color(BLACK),
                    100,
                    320,
                    true,
                    true,
                    true,
                    true
                );
                return goomba;
            default:
                return nullptr;
        }
    }
}