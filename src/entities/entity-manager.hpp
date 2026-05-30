#pragma once

#include "entity-profile.hpp"
#include "entity.hpp"

class EntityManager {
    private:
        int num_conceived_entities = 0;
        int next_entity_id = 0;
    public:
        Entity* entity_registry;
        int num_entities = 0;
        int num_entity_registers;

        EntityManager(int num_entity_registers);
        ~EntityManager();

        int conceiveEntity(const EntityConfiguration entity_configuration);
        void condemnEntity(int entity_id);
        void updateEntities();
};