#define NUM_BUTTONS 4
enum Button {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

class ButtonState {
    bool is_on;
    bool is_transition;
};

class Controller {
    public:
        virtual ButtonState getButtonState(Button) = 0;
};