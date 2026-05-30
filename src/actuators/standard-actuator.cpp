#include "actuators/standard-actuator.hpp"
#include "controller.hpp"
#include "entities/entity.hpp"
#include "utilities/enum-map.hpp"

void StandardActuator::actuate(Entity& entity) {
    EnumMap<Button, ButtonState> button_states = controller->getButtonStates();
    int x_acceleration = 0;
    if (button_states[Button::LEFT] == HIGH || button_states[Button::LEFT] == RISING_EDGE) {
        x_acceleration -= walking_acceleration;
    }
    if (button_states[Button::RIGHT] == HIGH || button_states[Button::RIGHT] == RISING_EDGE) {
        x_acceleration += walking_acceleration;
    }
    if (button_states[Button::UP] == RISING_EDGE) {
        entity.state.velocity.y = jumping_velocity;
    }
    entity.state.acceleration.x = x_acceleration;

}