#pragma once

#include "utilities/enum-map.hpp"

enum class Button {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
    DEBUGS,

    COUNT
};

enum ButtonState {
    IS_HIGH = (1 << 0),
    IS_EDGE = (1 << 1),
    RISING_EDGE = IS_HIGH|IS_EDGE,
    FALLING_EDGE = IS_EDGE&(~IS_HIGH),
    STABLE_HIGH = IS_HIGH&~(IS_EDGE),
    STABLE_LOW = 0&~(IS_HIGH)&~(IS_EDGE),
};

class Controller {
    public:
        virtual ButtonState getButtonState(Button) = 0;
        virtual EnumMap<Button, ButtonState>& getButtonStates() = 0;
};