#pragma once

#include "actuators/actuator.hpp"

class StandardActuator : public Actuator {
    private:
        int walking_target_velocity;
        int jumping_velocity;
    public:
        void actuate(Entity& entity) override;
        StandardActuator(
            int walking_target_velocity,
            int jumping_velocity
        )
        : walking_target_velocity(walking_target_velocity)
        , jumping_velocity(jumping_velocity) {}
};