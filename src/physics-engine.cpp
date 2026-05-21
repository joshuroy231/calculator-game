#include "physics-engine.hpp"

PhysicsEngine::PhysicsEngine(Entity* entity_registry, int const& num_entities)
: entity_registry(entity_registry)
, num_entities(num_entities) {}


void PhysicsEngine::simulate() {
    for (int i = 0; i < this->num_entities; i++) {
        Entity entity = this->entity_registry[i];

        if (entity.velocity.x < entity.target_velocity.x) entity.velocity.x += 1;
        else if (entity.velocity.x > entity.target_velocity.x) entity.velocity.x -= 1;
        if (entity.velocity.y < entity.target_velocity.y) entity.velocity.y += 1;
        else if (entity.velocity.y > entity.target_velocity.y) entity.velocity.y -= 1;

        entity.position.x += entity.velocity.x;
        entity.position.y += entity.velocity.y;
    }
}