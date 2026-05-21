#include <stdlib.h>
#include "entity-manager.hpp"

EntityManager::EntityManager(int num_entity_registers) {
    this->num_entity_registers = num_entity_registers;
    this->entity_registry = new Entity[num_entity_registers];
}
EntityManager::~EntityManager() {
    delete[] entity_registry;
}
int EntityManager::registerEntity() {
    entity_registry[num_entities++] = Entity(next_entity_id);
    return next_entity_id++;
}
void EntityManager::unregisterEntity(int entity_id) {
    for (int i = 0; i < num_entities; i++) {
        if (entity_registry[i].entity_id == entity_id) {
            entity_registry[i] = entity_registry[num_entities - 1];
            num_entities--;
            return;
        }
    }
}
Entity* EntityManager::getEntity(int entity_id) {
    for (int i = 0; i < num_entities; i++) {
        if (entity_registry[i].entity_id = entity_id) {
            return entity_registry + i;
        }
    }
    return nullptr;
}
Entity* EntityManager::getEntities() {
    return entity_registry;
}

EntityBuilder* EntityBuilder::setPosition(Position position) {
    this->position = position;
    return this;
}
EntityBuilder* EntityBuilder::setDimensions(Dimensions dimensions) {
    this->dimensions = dimensions;
    return this;
}
EntityBuilder* EntityBuilder::setVelocity(Velocity velocity) {
    this->velocity = velocity;
    return this;
}
EntityBuilder* EntityBuilder::setTargetVelocity(Velocity target_velocity) {
    this->target_velocity = target_velocity;
    return this;
}
EntityBuilder* EntityBuilder::setColor(Color color) {
    this->color = color;
    return this;
}
EntityBuilder* EntityBuilder::setAsRenderingEntity() {
    this->is_rendering_entity = true;
    return this;
}
EntityBuilder* EntityBuilder::setAsPhysicsEntity() {
    this->is_physics_entity = true;
    return this;
}
int EntityBuilder::registerEntity() {
    Entity entity = entity;
    if (this->is_physics_entity) {

    }
}