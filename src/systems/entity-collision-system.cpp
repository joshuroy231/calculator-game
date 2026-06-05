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

            Vec2<int> center1 = entity1.state.position + entity1.profile->dimensions/2;
            Vec2<int> center2 = entity2.state.position + entity2.profile->dimensions/2;
            Vec2<int> difference = center2 - center1;
            Vec2<int> overlap;
            if (difference.x > 0)
                overlap.x = box2.x_min - box1.x_max;
            else
                overlap.x = box2.x_max - box1.x_min;
            if (difference.y > 0)
                overlap.y = box2.y_min - box1.y_max;
            else
                overlap.y = box2.y_max - box1.y_min;
            
            Vec2<int> relative_velocity = entity2.state.velocity - entity1.state.velocity;
            int adjusted_y_overlap = overlap.y * relative_velocity.x;
            int adjusted_y_velocity = relative_velocity.y * overlap.x;

            if (abs(adjusted_y_velocity) > abs(adjusted_y_overlap)) {
                if (difference.y*relative_velocity.y > 0) return;
                entity1.state.position.y += overlap.y - overlap.y/2;
                entity2.state.position.y -= overlap.y/2;
                entity1.state.velocity.y = entity2.state.velocity.y = (entity1.state.velocity.y + entity2.state.velocity.y)/2;
            }
            else {
                if (difference.x*relative_velocity.x > 0) return;
                entity1.state.position.x += overlap.x - overlap.x/2;
                entity2.state.position.x -= overlap.x/2;
                entity1.state.velocity.x = entity2.state.velocity.x = (entity1.state.velocity.x + entity2.state.velocity.x)/2;
            }

            OnCollisionFunction on_collision = collision_matrix[entity1.profile_id][entity2.profile_id];
            if (on_collision != nullptr) {
                dbg_printf("Called on collision between %d and %d\n", entity1.id, entity2.id);
                on_collision(entity1, entity2, event_queue);
            }
        }
    }
}