#include "systems/entity-collision-system.hpp"

#include "utilities/helpers.hpp"

void EntityCollisionSystem::update() {
    for (int i = 0; i < num_entities; i++) {
        Entity& entity1 = entity_registry[i];
        if (!entity1.profile->has_collision) continue;
        for (int j = i+1; j < num_entities; j++) {
            Entity& entity2 = entity_registry[j];
            if (!entity2.profile->has_collision) continue;
            if (!areColliding(entity1.state.position, entity1.profile->dimensions,
                entity2.state.position, entity2.profile->dimensions)) continue;

            Vec2<int> center1 = entity1.state.position + entity1.profile->dimensions/2;
            Vec2<int> center2 = entity2.state.position + entity2.profile->dimensions/2;
            Vec2<int> difference = center2 - center1;
            Vec2<int> overlap;
            if (difference.x > 0)
                overlap.x = entity2.state.position.x - (entity1.state.position.x + entity1.profile->dimensions.x);
            else
                overlap.x = entity2.state.position.x + entity2.profile->dimensions.x - entity1.state.position.x;
            if (difference.y > 0)
                overlap.y = entity2.state.position.y - (entity1.state.position.y + entity1.profile->dimensions.y);
            else
                overlap.y = entity2.state.position.y + entity2.profile->dimensions.y - entity1.state.position.y;

            if (abs(overlap.x) > abs(overlap.y)) {
                entity1.state.position.y += overlap.y - overlap.y/2;
                entity2.state.position.y -= overlap.y/2;
                entity1.state.velocity.y = entity2.state.velocity.y = (entity1.state.velocity.y + entity2.state.velocity.y)/2;
            }
            else {
                entity1.state.position.x += overlap.x - overlap.x/2;
                entity2.state.position.x -= overlap.x/2;
                entity1.state.velocity.x = entity2.state.velocity.x = (entity1.state.velocity.x + entity2.state.velocity.x)/2;
            }
        }
    }
}