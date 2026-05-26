#include "actuators/standard-actuator.hpp"
#include "controller.hpp"
#include "entities/entity.hpp"

void StandardActuator::actuate(Entity& entity) {
    ButtonState* button_states = entity.profile->control.controller->getButtonStates();
    int x_acceleration = 0;
    if (button_states[LEFT] == HIGH || button_states[LEFT] == RISING_EDGE) {
        x_acceleration -= entity.profile->walking_acceleration;
    }
    if (button_states[RIGHT] == HIGH || button_states[RIGHT] == RISING_EDGE) {
        x_acceleration += entity.profile->walking_acceleration;
    }
    if (x_acceleration == 0) {
        if (entity.state.velocity.x > 0) x_acceleration = -entity.profile->walking_acceleration;
        else if (entity.state.velocity.x < 0) x_acceleration = entity.profile->walking_acceleration;
    }
    if (button_states[UP] == RISING_EDGE) {
        entity.state.velocity.y = entity.profile->jumping_velocity.y;
    }
    entity.state.acceleration.x = x_acceleration;

}