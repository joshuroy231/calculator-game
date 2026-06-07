#include "systems/entity-collision-system.hpp"

#include <debug.h>

#include "utilities/helpers.hpp"

void EntityCollisionSystem::update() {
    for (int i = 0; i < num_entities; i++) {
        Entity& entity1 = entity_registry[i];
        if (!entity1.profile->has_collision) continue;
        for (int j = i+1; j < num_entities; j++) {
            Entity& entity2 = entity_registry[j];
            if (!entity2.profile->has_collision) continue;
            Box<int> box1 = Box(entity1.state.position, entity1.profile->dimensions);
            Box<int> box2 = Box(entity2.state.position, entity2.profile->dimensions);
            if (!areColliding(box1, box2)) continue;

            Vec2<int> collision = getCollision(box1, entity1.state.velocity, box2, entity2.state.velocity);

            entity1.state.position += collision - collision/2;
            entity2.state.position -= collision/2;
            if (collision.x != 0) {
                entity1.state.velocity.x = entity2.state.velocity.x = (entity1.state.velocity.x + entity2.state.velocity.x)/2;
            }
            else if (collision.y != 0) {
                entity1.state.velocity.y = entity2.state.velocity.y = (entity1.state.velocity.y + entity2.state.velocity.y)/2;
            }

            OnCollisionFunction on_collision = collision_matrix[entity1.profile_id][entity2.profile_id];
            if (on_collision != nullptr) {
                on_collision(entity1, entity2, event_queue);
            }
        }
    }
}