#pragma once

#include <stdint.h>

enum ColorType {
    BLACK = 0,
    WHITE = 255,
    RED = 224,
    ORANGE = 227,
    YELLOW = 231,
    GREEN = 36,
    BLUE = 24,
    LIGHT_BLUE = 30,
    PURPLE = 80,
    PINK = 248,
    GRAY =  148,
    GREY = 75,
};

struct Color {
    uint8_t color = 0;
    Color() = default;
    Color(uint8_t color)
    : color(color) {}
};