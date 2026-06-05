#pragma once

#include "entities/entity.hpp"
#include "entities/entity-configuration.hpp"
#include "utilities/queue.hpp"
#include "events/event.hpp"

class EntityManager {
    private:
        int num_entity_registers;
        EntityProfile* entity_profiles;
        Queue<Event>& event_queue;
        int num_conceived_entities = 0;
        int next_id = 0;
    public:
        Entity* entity_registry;
        int num_entities = 0;

        EntityManager(
            int num_entity_registers,
            EntityProfile* entity_profiles,
            Queue<Event>& event_queue
        );
        ~EntityManager();

        int conceiveEntity(const EntityConfiguration entity_configuration);
        void condemnEntity(int id);
        void updateEntities();
        void consumeEvents();
};