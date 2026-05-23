#include "physics-system.hpp"

PhysicsSystem::PhysicsSystem(Entity* entity_registry, int const& num_entities)
: System(entity_registry, num_entities) {}


void PhysicsSystem::update() {
    for (int i = 0; i < this->num_entities; i++) {
        if (!entity_registry[i].entity_profile->has_physics) continue;
        Entity& entity = this->entity_registry[i];

        if (entity.velocity.x < entity.target_velocity.x) entity.velocity.x += 1;
        else if (entity.velocity.x > entity.target_velocity.x) entity.velocity.x -= 1;
        if (entity.velocity.y < entity.target_velocity.y) entity.velocity.y += 1;
        else if (entity.velocity.y > entity.target_velocity.y) entity.velocity.y -= 1;

        entity.position.x += entity.velocity.x;
        entity.position.y += entity.velocity.y;
    }
}