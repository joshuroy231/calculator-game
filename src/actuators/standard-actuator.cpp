#include "actuators/standard-actuator.hpp"
#include "controller.hpp"
#include "entities/entity.hpp"

void StandardActuator::actuate(Entity& entity) {
    ButtonState* button_states = entity.entity_profile->control.controller->getButtonStates();
    int target_velocity_x = 0;
    if (button_states[LEFT] == HIGH || button_states[LEFT] == RISING_EDGE) {
        target_velocity_x -= this->walking_target_velocity;
    }
    if (button_states[RIGHT] == HIGH || button_states[RIGHT] == RISING_EDGE) {
        target_velocity_x += this->walking_target_velocity;
    }
    if (button_states[UP] == RISING_EDGE) {
        entity.velocity.y = -this->jumping_velocity;
    }
    entity.target_velocity.x = target_velocity_x;

}