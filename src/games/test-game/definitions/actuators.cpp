#include "games/test-game/definitions/actuators.hpp"

namespace Actuators {
    Actuator* get() {
        return new StandardActuator();
    }
}