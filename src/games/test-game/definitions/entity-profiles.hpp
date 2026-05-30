#pragma once

#include "entities/entity-profile.hpp"

enum class EntityProfileId {
    PLAYER,
    MYSTERY_BOX,

    COUNT
};

namespace EntityProfiles {
    EntityProfile* get(EntityProfileId id);
}