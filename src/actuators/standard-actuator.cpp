#include "actuators/standard-actuator.hpp"
#include "controller.hpp"
#include "entities/entity.hpp"

void StandardActuator::actuate(Entity& entity) {
    ButtonState* button_states = entity.entity_profile->control.controller->getButtonStates();
    int x_acceleration = 0;
    if (button_states[LEFT] == HIGH || button_states[LEFT] == RISING_EDGE) {
        x_acceleration -= entity.entity_profile->walking_acceleration;
    }
    if (button_states[RIGHT] == HIGH || button_states[RIGHT] == RISING_EDGE) {
        x_acceleration += entity.entity_profile->walking_acceleration;
    }
    if (x_acceleration == 0) {
        if (entity.velocity.x > 0) x_acceleration = -entity.entity_profile->walking_acceleration;
        else if (entity.velocity.x < 0) x_acceleration = entity.entity_profile->walking_acceleration;
    }
    if (button_states[UP] == RISING_EDGE) {
        entity.velocity.y = entity.entity_profile->jumping_velocity.y;
    }
    entity.acceleration.x = x_acceleration;

}