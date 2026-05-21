#define NUM_BUTTONS 4
enum Button {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum ButtonState {
    ON,
    OFF,
    PRESS,
    RELEASE,
};

class Controller {
    public:
        virtual ButtonState getButtonState(Button) = 0;
};