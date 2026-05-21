#include <keypadc.h>
#include "keypad.hpp"

kb_lkey_t keymap[NUM_BUTTONS];

Keypad::Keypad() {
    keymap[LEFT] = kb_Left;
    keymap[RIGHT] = kb_Right;
    keymap[UP] = kb_Up;
    keymap[DOWN] = kb_Down;

    for (int i = 0; i < NUM_BUTTONS; i++) {
        this->key_states[i] = LOW;
    }
}

ButtonState Keypad::getButtonState(Button button) {
    return key_states[button];
}

void Keypad::scan() {
    kb_Scan();
    for (int i = 0; i < NUM_BUTTONS; i++) {
        if (kb_IsDown(keymap[i])) {
            key_states[i] = (key_states[i] == LOW) ? RISING_EDGE : HIGH;
        }
        else {
            key_states[i] = (key_states[i] == HIGH) ? FALLING_EDGE : LOW;
        }
    }
}