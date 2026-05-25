#pragma once

#include "entity-profile.hpp"
#include "components.hpp"
#include "utilities/vec2.hpp"

class Entity {
    friend class EntityManager;
    private:
        bool is_condemned = false;
        int entity_id;
    public:
        const EntityProfile* entity_profile;

        Vec2<int> position;
        Vec2<int> velocity;
        Vec2<int> target_velocity;

        Entity() = default;
        Entity(int entity_id)
        : entity_id(entity_id) {}
};