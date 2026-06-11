#include "entity-manager.hpp"
#include "entity.hpp"
#include "actuators/actuator.hpp"

EntityManager::EntityManager(
    int num_entity_registers,
    EntityProfile* entity_profiles,
    Queue<Event>& event_queue
) 
: num_entity_registers(num_entity_registers)
, entity_profiles(entity_profiles)
, event_queue(event_queue)
{
    this->entity_registry = new Entity[num_entity_registers];
}
EntityManager::~EntityManager() {
    delete[] entity_registry;
}
int EntityManager::conceiveEntity(const EntityConfiguration entity_configuration) {
    if (num_entities + num_conceived_entities == num_entity_registers) return -1;

    Entity new_entity = Entity(next_id);
    new_entity.profile_id = entity_configuration.profile_id;
    new_entity.state = entity_configuration.initial_state;
    new_entity.profile = &entity_profiles[entity_configuration.profile_id];
    new_entity.actuator = entity_configuration.actuator;

    entity_registry[num_entities + num_conceived_entities] = new_entity;
    num_conceived_entities++;
    return next_id++;
}
void EntityManager::condemnEntity(int id) {
    for (int i = 0; i < num_entities + num_conceived_entities; i++) {
        if (entity_registry[i].id == id) {
            entity_registry[i].is_condemned = true;
        }
    }
}
void EntityManager::updateEntities() {
    int write_ptr = 0;
    int read_ptr = 0;
    for (; read_ptr < num_entities + num_conceived_entities; read_ptr++) {
        if (entity_registry[read_ptr].is_condemned) {
            delete entity_registry[read_ptr].actuator;
            continue;
        }
        else {
            entity_registry[write_ptr] = entity_registry[read_ptr];
            write_ptr++;
        }
    }
    num_entities = write_ptr;
    num_conceived_entities = 0;
}
void EntityManager::consumeEvents() {
    for (Event& e : event_queue) {
        switch (e.getEventType()) {
            case EventType::CONDEMN_ENTITY:
                condemnEntity(e.event_data.condemn_entity.id);
                continue;
            case EventType::CONCEIVE_ENTITY:
                conceiveEntity(e.event_data.conceive_entity.entity_configuration);
                continue;
            default:
                continue;
        }
    }
}