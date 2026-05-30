#pragma once

#include "entities/entity-profile.hpp"

namespace EntityProfiles {
    enum class Id {
        PLAYER,
        MYSTERY_BOX,

        COUNT,
    };
    EntityProfile* get(Id id);
}