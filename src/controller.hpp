#pragma once

#define NUM_BUTTONS 4
enum Button {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum ButtonState {
    HIGH,
    LOW,
    RISING_EDGE,
    FALLING_EDGE,
};

class Controller {
    public:
        virtual ButtonState getButtonState(Button) = 0;
        virtual ButtonState* getButtonStates() = 0;
};