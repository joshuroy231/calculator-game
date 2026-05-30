#pragma once

#include "actuators/actuator.hpp"

class StandardActuator : public Actuator {
    private:
        int jumping_velocity;
        int walking_acceleration;
    public:
        void actuate(Entity& entity) override;
        StandardActuator(
            Controller* controller,
            int jumping_velocity,
            int walking_acceleration
        )
        : Actuator(controller)
        , jumping_velocity(jumping_velocity)
        , walking_acceleration(walking_acceleration) {}
};