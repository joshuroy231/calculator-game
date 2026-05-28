#pragma once

#include "controller.hpp"

class Keypad : public Controller {
    private:
        ButtonState key_states[Button::SIZE];
    public:
        Keypad();
        ButtonState getButtonState(Button) override;
        ButtonState* getButtonStates() override;
        void scan();
};