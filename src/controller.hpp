#pragma once

#define NUM_BUTTONS 5
enum Button {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
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