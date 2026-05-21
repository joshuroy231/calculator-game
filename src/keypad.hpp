#pragma once

#include "controller.hpp"

class Keypad : public Controller {
    private:
        ButtonState key_states[NUM_BUTTONS];
    public:
        Keypad();
        ButtonState getButtonState(Button) override;
        void scan();
};