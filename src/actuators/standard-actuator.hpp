#pragma once

#include "actuators/actuator.hpp"

class StandardActuator : public Actuator {
    private:
    public:
        void actuate(Entity& entity) override;
        StandardActuator() = default;
};