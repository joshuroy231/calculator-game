#pragma once

#include <stdint.h>
#include "controller.hpp"

struct Position {
    int x = 0;
    int y = 0;
    Position() = default;
    Position(int x, int y)
    : x(x)
    , y(y) {}
};

struct Dimensions {
    int w = 0;
    int h = 0;
    Dimensions() = default;
    Dimensions(int w, int h)
    : w(w)
    , h(h) {}
};

struct Color {
    uint8_t color = 0;
    Color() = default;
    Color(uint8_t color)
    : color(color) {}
};

struct Velocity {
    int x = 0;
    int y = 0;
    Velocity() = default;
    Velocity(int x, int y)
    : x(x)
    , y(y) {}
};

struct Control {
    Controller* controller;
    void (*control)(Entity*);
};