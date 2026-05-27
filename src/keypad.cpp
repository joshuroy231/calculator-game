#include <keypadc.h>
#include <debug.h>
#include "keypad.hpp"

kb_lkey_t keymap[NUM_BUTTONS];

Keypad::Keypad() {
    keymap[LEFT] = kb_KeyLeft;
    keymap[RIGHT] = kb_KeyRight;
    keymap[UP] = kb_KeyUp;
    keymap[DOWN] = kb_KeyDown;
    keymap[QUIT] = kb_KeyClear;
    keymap[DEBUG_KEY] = kb_KeyDecPnt;

    for (int i = 0; i < NUM_BUTTONS; i++) {
        this->key_states[i] = LOW;
    }
}

ButtonState Keypad::getButtonState(Button button) {
    return key_states[button];
}
ButtonState* Keypad::getButtonStates() {
    return key_states;
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