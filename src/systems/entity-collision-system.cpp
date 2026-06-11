#include "systems/entity-collision-system.hpp"

#include <debug.h>

#include "utilities/helpers.hpp"
#include "game.hpp"

void EntityCollisionSystem::update() {
    for (int i = 0; i < *num_entities; i++) {
        Entity& entity1 = entity_registry[i];
        if (entity1.profile->collision_behavior == CollisionBehavior::NONE) continue;
        for (int j = i+1; j < *num_entities; j++) {
            Entity& entity2 = entity_registry[j];
            if (entity2.profile->collision_behavior == CollisionBehavior::NONE) continue;
            if (entity1.profile->collision_behavior == CollisionBehavior::SOLID && entity2.profile->collision_behavior == CollisionBehavior::SOLID) continue;
            Box<int> box1 = Box(entity1.state.position, entity1.profile->dimensions);
            Box<int> box2 = Box(entity2.state.position, entity2.profile->dimensions);
            if (!areColliding(box1, box2)) continue;

            Vec2<int> collision = getCollision(box1, entity1.state.velocity, box2, entity2.state.velocity);

            if (!(entity1.profile->collision_behavior == CollisionBehavior::INVISIBLE) && !(entity2.profile->collision_behavior == CollisionBehavior::INVISIBLE)) {
                if (entity1.profile->collision_behavior == CollisionBehavior::MATERIAL && entity2.profile->collision_behavior == CollisionBehavior::MATERIAL) {
                    entity1.state.position += collision - collision/2;
                    entity2.state.position -= collision/2;
                    if (collision.x != 0) {
                        entity1.state.velocity.x = entity2.state.velocity.x = (entity1.state.velocity.x + entity2.state.velocity.x)/2;
                    }
                    else if (collision.y != 0) {
                        entity1.state.velocity.y = entity2.state.velocity.y = (entity1.state.velocity.y + entity2.state.velocity.y)/2;
                    }
                }
                else if (entity1.profile->collision_behavior == CollisionBehavior::MATERIAL && entity2.profile->collision_behavior == CollisionBehavior::SOLID) {
                    entity1.state.position += collision;
                    if (collision.x != 0) {
                        entity1.state.velocity.x = 0;
                    }
                    else if (collision.y != 0) {
                        entity1.state.velocity.y = 0;
                    }
                }
                else if (entity1.profile->collision_behavior == CollisionBehavior::SOLID && entity2.profile->collision_behavior == CollisionBehavior::MATERIAL) {
                    entity2.state.position -= collision;
                    if (collision.x != 0) {
                        entity2.state.velocity.x = 0;
                    }
                    else if (collision.y != 0) {
                        entity2.state.velocity.y = 0;
                    }
                }
            }

            OnCollisionFunction on_collision = (*collision_matrix)[entity1.profile_id][entity2.profile_id];
            if (on_collision != nullptr) {
                Direction direction;
                if (collision.x != 0) {
                    if (collision.x > 0) direction = Direction::LEFT;
                    else direction = Direction::RIGHT;
                }
                else {
                    if (collision.y > 0) direction = Direction::UP;
                    else direction = Direction::DOWN;
                }
                on_collision(entity1, entity2, direction, *event_queue);
            }
        }
    }
}

void EntityCollisionSystem::initGame(Game* game) {
    this->collision_matrix = &game->collision_matrix;
}