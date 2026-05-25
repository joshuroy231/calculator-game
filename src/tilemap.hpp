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
        const int num_cols;
        const int num_rows;
        const uint8_t* const data;
        const TileType* const tile_types;

        Tilemap(
            int num_cols,
            int num_rows,
            const uint8_t* const data,
            const TileType* const tile_types
        )
        : num_cols(num_cols)
        , num_rows(num_rows)
        , data(data)
        , tile_types(tile_types) {}
};