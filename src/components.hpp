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

struct Velocity {
    int x = 0;
    int y = 0;
    Velocity() = default;
    Velocity(int x, int y)
    : x(x)
    , y(y) {}
};

class Entity;

struct Control {
    Controller* controller = nullptr;
    void (*control)(Entity*) = nullptr;
    Control() = default;
    Control(Controller* controller, void (*control)(Entity*))
    : controller(controller)
    , control(control) {}
};