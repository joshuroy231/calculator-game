#pragma once

#include "system.hpp"
#include "entities/entity.hpp"

class ControlSystem : public System {
    public:
        ControlSystem() = default;
        void update() override;
};