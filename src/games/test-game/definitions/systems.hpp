#pragma once

#include "systems/system.hpp"
#include "utilities/fixed-vector.hpp"

namespace Systems {
    enum Id {
        CONTROL,
        PHYSICS,
        ENTITY_COLLISION,
        CAMERA,
        RENDERING,

        COUNT
    };
    FixedVector<System*> get();
}