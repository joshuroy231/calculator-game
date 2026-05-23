#pragma once

#include <stdint.h>
#include "device-properties.hpp"

#define TILE_PIXELS 16

class Tilemap {
    private:
        int num_cols = SCREEN_WIDTH_PIXELS/TILE_PIXELS;
        int num_rows = SCREEN_HEIGHT_PIXELS/TILE_PIXELS;
    public:
        uint8_t* data;

        Tilemap();
        Tilemap(uint8_t* data)
        : data(data) {}
        uint8_t at(int col, int row);
};