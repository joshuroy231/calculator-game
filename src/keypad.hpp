enum Key {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ENTER,
};

const int NUM_KEYS = 5;

enum KeyState {
    OFF,
    ON,
    PRESS,
    RELEASE,
};

class Keypad {
    private:
        KeyState key_states[NUM_KEYS];
    public:
        Keypad();
        KeyState* getKeyStates();
        void scan();
};