#pragma once

#include "tilemap.hpp"

namespace Tilemaps {
    enum class Id {
        MAIN,

        COUNT
    };
    Tilemap get(Id id);
}