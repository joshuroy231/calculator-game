#pragma once

#include "controller.hpp"
#include "utilities/enum-map.hpp"

class Keypad : public Controller {
    private:
        EnumMap<Button, ButtonState> key_states;
    public:
        Keypad();
        ButtonState getButtonState(Button) override;
        EnumMap<Button, ButtonState>& getButtonStates() override;
        void scan();
};