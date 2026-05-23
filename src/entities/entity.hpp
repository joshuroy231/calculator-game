#pragma once

#include "entity-profile.hpp"
#include "components.hpp"

class Entity {
    friend class EntityManager;
    private:
        bool is_condemned = false;
        int entity_id;
    public:
        const EntityProfile* entity_profile;

        Position position;
        Velocity velocity;
        Velocity target_velocity;

        Entity() = default;
        Entity(int entity_id)
        : entity_id(entity_id) {}
};