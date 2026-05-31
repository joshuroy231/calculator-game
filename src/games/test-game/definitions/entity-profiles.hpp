#pragma once

#include "entities/entity-profile.hpp"

namespace EntityProfiles {
    enum class Id {
        PLAYER,
        MYSTERY_BOX,
        GOOMBA,

        COUNT,
    };
    EntityProfile* get(Id id);
}