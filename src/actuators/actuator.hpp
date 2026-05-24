#pragma once

class Entity;

class Actuator {
    public:
        virtual void actuate(Entity& entity) = 0;
};