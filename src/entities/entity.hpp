#pragma once

#include "entities/entity-profile.hpp"
#include "entities/entity-state.hpp"
#include "components.hpp"
#include "utilities/vec2.hpp"

class Actuator;

class Entity {
    friend class EntityManager;
    private:
        bool is_condemned = false;
    public:
        int entity_id;
        const EntityProfile* profile;
        EntityState state;
        Actuator* actuator;

        Entity() = default;
        Entity(int entity_id)
        : entity_id(entity_id) {}
};