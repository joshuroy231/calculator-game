#include "entity-manager.hpp"

EntityManager::EntityManager(int num_entity_registers) {
    this->num_entity_registers = num_entity_registers;
    this->entity_registry = new Entity[num_entity_registers];
}
EntityManager::~EntityManager() {
    delete[] entity_registry;
}
int EntityManager::conceiveEntity(const EntityConfiguration entity_configuration) {
    if (num_entities + num_conceived_entities == num_entity_registers) return -1;

    Entity new_entity = Entity(next_entity_id);

    new_entity.position = entity_configuration.position;
    new_entity.dimensions = entity_configuration.dimensions;
    new_entity.velocity = entity_configuration.velocity;
    new_entity.target_velocity = entity_configuration.target_velocity;
    new_entity.color = entity_configuration.color;
    new_entity.control = entity_configuration.control;

    new_entity.has_rendering = entity_configuration.has_rendering;
    new_entity.has_physics = entity_configuration.has_physics;
    new_entity.has_control = entity_configuration.has_control;

    entity_registry[num_entities + num_conceived_entities] = new_entity;
    num_conceived_entities++;
    return next_entity_id++;
}
void EntityManager::condemnEntity(int entity_id) {
    for (int i = 0; i < num_entities + num_conceived_entities; i++) {
        if (entity_registry[i].entity_id == entity_id) {
            entity_registry[i].is_condemned = true;
        }
    }
}
void EntityManager::updateEntities() {
    int write_ptr = 0;
    int read_ptr = 0;
    for (; read_ptr < num_entities + num_conceived_entities; read_ptr++) {
        if (entity_registry[read_ptr].is_condemned) continue;
        else {
            entity_registry[write_ptr] = entity_registry[read_ptr];
            write_ptr++;
        }
    }
    num_entities = write_ptr;
    num_conceived_entities = 0;
}