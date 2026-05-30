#pragma once

#include "tilemap.hpp"

namespace Tilemaps {
    enum class Id {
        MAIN,

        COUNT
    };
    const Tilemap get(Id id);
}