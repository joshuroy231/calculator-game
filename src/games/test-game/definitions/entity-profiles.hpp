#pragma once

#include "entities/entity-profile.hpp"

namespace EntityProfiles {
    enum Id {
        PLAYER,
        MYSTERY_BOX,
        GOOMBA,

        COUNT,
    };
    EntityProfile* get();
}