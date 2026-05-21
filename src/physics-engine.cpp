#include "physics-engine.hpp"

PhysicsEngine::PhysicsEngine() {
    for (int i = 0; i < NUM_PHYSICS_ENTITY_SLOTS; i++) {
        this->available_slots[i] = AVAILABLE;
    }
}

int PhysicsEngine::registerPhysicsEntity(
    Position* position,
    Dimensions* dimensions,
    Velocity* velocity,
    Velocity* target_velocity
) {
    for (int i = 0; i < NUM_PHYSICS_ENTITY_SLOTS; i++) {
        if (this->available_slots[i] == AVAILABLE) {
            int new_physics_entity_id = i;
            PhysicsEntity new_physics_entity = PhysicsEntity(position, dimensions, velocity, target_velocity);
            this->entity_register[i] = new_physics_entity;
            return new_physics_entity_id;
        }
    }
}

void PhysicsEngine::unregisterPhysicsEntity(int physics_entity_id) {
    if (physics_entity_id < 0 || physics_entity_id >= NUM_PHYSICS_ENTITY_SLOTS) return;
    this->available_slots[physics_entity_id] = UNAVAILABLE;
}

void PhysicsEngine::simulate() {
    for (int i = 0; i < NUM_PHYSICS_ENTITY_SLOTS; i++) {
        if (this->available_slots[i] == UNAVAILABLE) {
            PhysicsEntity entity = this->entity_register[i];

            if (entity.velocity->x < entity.target_velocity->x) entity.velocity->x += 1;
            else if (entity.velocity->x > entity.target_velocity->x) entity.velocity->x -= 1;
            if (entity.velocity->y < entity.target_velocity->y) entity.velocity->y += 1;
            else if (entity.velocity->y > entity.target_velocity->y) entity.velocity->y -= 1;

            entity.position->x += entity.velocity->x;
            entity.position->y += entity.velocity->y;
        }
    }
}