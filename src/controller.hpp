#pragma once

#include "utilities/enum-map.hpp"

enum class Button {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
    DEBUG,

    SIZE
};

enum ButtonState {
    LOW,
    HIGH,
    RISING_EDGE,
    FALLING_EDGE,
};

class Controller {
    public:
        virtual ButtonState getButtonState(Button) = 0;
        virtual EnumMap<Button, ButtonState>& getButtonStates() = 0;
};