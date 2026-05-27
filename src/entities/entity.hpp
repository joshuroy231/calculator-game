#pragma once

#include "entity-profile.hpp"
#include "components.hpp"
#include "utilities/vec2.hpp"

class Entity {
    friend class EntityManager;
    private:
        bool is_condemned = false;
    public:
        int entity_id;
        const EntityProfile* profile;
        EntityState state;

        Entity() = default;
        Entity(int entity_id)
        : entity_id(entity_id) {}
};