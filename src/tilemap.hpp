#pragma once

#include <stdint.h>
#include "device-properties.hpp"

#define TILE_PIXELS 16

class Tilemap {
    private:
    public:
        const int num_cols;
        const int num_rows;
        uint8_t* data;

        Tilemap(
            int num_cols,
            int num_rows,
            uint8_t* data
        )
        : num_cols(num_cols)
        , num_rows(num_rows)
        , data(data) {}
};