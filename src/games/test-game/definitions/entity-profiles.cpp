#include "games/test-game/definitions/entity-profiles.hpp"
#include "games/test-game/definitions/actuators.hpp"
#include "keypad.hpp"
#include "device-properties.hpp"

namespace EntityProfiles {
    EntityProfile* init();

    EntityProfile* get() {
        static EntityProfile* profiles = init();
        return profiles;
    }

    EntityProfile* init() {
        static EntityProfile profiles[Id::COUNT];
        profiles[Id::PLAYER] = EntityProfile(
            Vec2<int>(12, 16),
            RED,
            160,
            320,
            true,
            true,
            true,
            true
        );
        profiles[Id::MYSTERY_BOX] = EntityProfile(
            Vec2<int>(32, 32),
            YELLOW,
            160,
            320,
            true,
            true,
            false,
            true
        );
        profiles[Id::GOOMBA] = EntityProfile(
            Vec2<int>(16,16),
            BLACK,
            100,
            320,
            true,
            true,
            true,
            true
        );
        return profiles;
    }
}