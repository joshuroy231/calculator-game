#include <keypadc.h>
#include <debug.h>
#include "keypad.hpp"
#include "utilities/enum-map.hpp"
#include "utilities/enum-set.hpp"

EnumMap<Button, kb_lkey_t> keymap;

Keypad::Keypad() {
    keymap[Button::LEFT] = kb_Key4;
    keymap[Button::RIGHT] = kb_Key6;
    keymap[Button::UP] = kb_Key8;
    keymap[Button::DOWN] = kb_Key2;
    keymap[Button::QUIT] = kb_KeyClear;
    keymap[Button::DEBUG] = kb_KeyDecPnt;

    for (ButtonState& state : key_states) {
        state = LOW;
    }
}

ButtonState Keypad::getButtonState(Button button) {
    return key_states[button];
}
EnumMap<Button, ButtonState>& Keypad::getButtonStates() {
    return key_states;
}

void Keypad::scan() {
    kb_Scan();
    for (Button button : EnumRange<Button>()) {
        if (kb_IsDown(keymap[button])) {
            key_states[button] = (key_states[button] == LOW) ? RISING_EDGE : HIGH;
        }
        else {
            key_states[button] = (key_states[button] == HIGH) ? FALLING_EDGE : LOW;
        }
    }
}