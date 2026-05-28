#pragma once

#include <stdint.h>
#include "device-properties.hpp"

#define TILE_PIXELS 16

class TileType {
    public:
        Color color;
        TileType(
            Color color
        )
        : color(color) {}
};

class Tilemap {
    private:
    public:
        const Vec2<int> tile_dimensions;
        const uint8_t* const data;
        const TileType* const tile_types;

        Tilemap(
            const Vec2<int> tile_dimensions,
            const uint8_t* const data,
            const TileType* const tile_types
        )
        : tile_dimensions(tile_dimensions)
        , data(data)
        , tile_types(tile_types) {}
};