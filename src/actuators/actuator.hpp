#pragma once

#include "controller.hpp"

class Entity;

class Actuator {
    protected:
        Controller* controller;
        Actuator(Controller* controller)
        : controller(controller) {}
    public:
        virtual void actuate(Entity& entity) = 0;
        virtual ~Actuator() = default;
};