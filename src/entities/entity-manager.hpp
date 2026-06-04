#pragma once

#include "entities/entity.hpp"
#include "entities/entity-configuration.hpp"

class EntityManager {
    private:
        int num_conceived_entities = 0;
        int next_id = 0;
    public:
        Entity* entity_registry;
        EntityProfile* entity_profiles;
        int num_entities = 0;
        int num_entity_registers;

        EntityManager(int num_entity_registers, EntityProfile* entity_profiles);
        ~EntityManager();

        int conceiveEntity(const EntityConfiguration entity_configuration);
        void condemnEntity(int id);
        void updateEntities();
};