#pragma once

#include "tilemap.hpp"

namespace Tilemaps {
    enum Id {
        MAIN,

        COUNT
    };
    Tilemap* get();
}