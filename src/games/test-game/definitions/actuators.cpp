#include "games/test-game/definitions/actuators.hpp"

namespace Actuators {
    enum class Id {
        PLAYER,

        COUNT
    };
    Actuator* get() {
        return new StandardActuator();
    }
}