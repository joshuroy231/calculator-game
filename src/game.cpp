#include "game.hpp"

Tilemap::Tilemap() {
    data = new uint8_t[num_rows*num_cols];
    for (int i = 0; i < num_rows*num_cols; i++) {
        data[i] = 0;
    }
}
uint8_t Tilemap::at(int col, int row) {
    return data[row*num_cols + col];
}