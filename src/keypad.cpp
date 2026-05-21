#include <keypadc.h>
#include "keypad.hpp"

kb_lkey_t keymap[NUM_KEYS];

Keypad::Keypad() {
    keymap[LEFT] = kb_Left;
    keymap[RIGHT] = kb_Right;
    keymap[UP] = kb_Up;
    keymap[DOWN] = kb_Down;
    keymap[ENTER] = kb_Enter;

    for (int i = 0; i < NUM_KEYS; i++) {
        this->key_states[i] = OFF;
    }
}

KeyState* Keypad::getKeyStates() {
    return this->key_states;
}

void Keypad::scan() {
    for (int i = 0; i < NUM_KEYS; i++) {
        if (kb_IsDown(keymap[i])) {
            this->key_states[i] = (this->key_states[i] == OFF) ? PRESS : ON;
        }
        else {
            this->key_states[i] = (this->key_states[i] == ON) ? RELEASE : OFF;
        }
    }
}