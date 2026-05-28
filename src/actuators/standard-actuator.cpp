#include "actuators/standard-actuator.hpp"
#include "controller.hpp"
#include "entities/entity.hpp"
#include "utilities/enum-map.hpp"

void StandardActuator::actuate(Entity& entity) {
    EnumMap<Button, ButtonState> button_states = entity.profile->control.controller->getButtonStates();
    int x_acceleration = 0;
    if (button_states[Button::LEFT] == HIGH || button_states[Button::LEFT] == RISING_EDGE) {
        x_acceleration -= entity.profile->walking_acceleration;
    }
    if (button_states[Button::RIGHT] == HIGH || button_states[Button::RIGHT] == RISING_EDGE) {
        x_acceleration += entity.profile->walking_acceleration;
    }
    if (button_states[Button::UP] == RISING_EDGE) {
        entity.state.velocity.y = entity.profile->jumping_velocity.y;
    }
    entity.state.acceleration.x = x_acceleration;

}