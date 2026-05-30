#include "games/test-game/definitions/actuators.hpp"
#include "keypad.hpp"

namespace Actuators {
    enum class Id {
        PLAYER,

        COUNT
    };
    Actuator* get() {
        return new StandardActuator(getStandardKeypad(), -256, 1536);
    }
}