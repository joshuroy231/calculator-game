#include "physics-system.hpp"

PhysicsSystem::PhysicsSystem(Entity* entity_registry, int const& num_entities, Tilemap* tilemap)
: System(entity_registry, num_entities)
, tilemap(tilemap)
{}

void resolveXCollision(Entity& entity, Tilemap* tilemap) {
    int top_index = entity.position.y / TILE_PIXELS;
    int bottom_coord = entity.position.y + entity.entity_profile->dimensions.h;
    int bottom_index = (bottom_coord % TILE_PIXELS == 0) ? (bottom_coord / TILE_PIXELS - 1) : (bottom_coord / TILE_PIXELS);
    if (entity.velocity.x > 0) {
        int right_index = (entity.position.x + entity.entity_profile->dimensions.w) / TILE_PIXELS;
        for (int i = top_index; i <= bottom_index; i++) {
            if (tilemap->data[i*tilemap->num_cols + right_index] != 0) {
                entity.position.x -= entity.position.x % TILE_PIXELS;
                entity.velocity.x = 0;
                break;
            }
        }
    }
    if (entity.velocity.x < 0) {
        int left_index = (entity.position.x) / TILE_PIXELS;
        for (int i = top_index; i <= bottom_index; i++) {
            if (tilemap->data[i*tilemap->num_cols + left_index] != 0) {
                entity.position.x += TILE_PIXELS;
                entity.position.x -= entity.position.x % TILE_PIXELS;
                entity.velocity.x = 0;
                break;
            }
        }
    }
}
void resolveYCollision(Entity& entity, Tilemap* tilemap) {
    int left_index = entity.position.x / TILE_PIXELS;
    int right_coord = entity.position.x + entity.entity_profile->dimensions.w;
    int right_index = (right_coord % TILE_PIXELS == 0) ? (right_coord / TILE_PIXELS - 1) : (right_coord / TILE_PIXELS);
    if (entity.velocity.y > 0) {
        int bottom_index = (entity.position.y + entity.entity_profile->dimensions.h) / TILE_PIXELS;
        for (int i = left_index; i <= right_index; i++) {
            if (tilemap->data[bottom_index*tilemap->num_cols + i] != 0) {
                entity.position.y -= entity.position.y % TILE_PIXELS;
                entity.velocity.y = 0;
                break;
            }
        }
    }
    if (entity.velocity.y < 0) {
        int top_index = (entity.position.y) / TILE_PIXELS;
        for (int i = left_index; i <= right_index; i++) {
            if (tilemap->data[top_index*tilemap->num_cols + i] != 0) {
                entity.position.y += TILE_PIXELS;
                entity.position.y -= entity.position.y % TILE_PIXELS;
                entity.velocity.y = 0;
                break;
            }
        }
    }
}

void PhysicsSystem::update() {
    for (int i = 0; i < this->num_entities; i++) {
        if (!entity_registry[i].entity_profile->has_physics) continue;
        Entity& entity = this->entity_registry[i];

        if (entity.velocity.x < entity.target_velocity.x) entity.velocity.x += 4;
        else if (entity.velocity.x > entity.target_velocity.x) entity.velocity.x -= 4;
        if (entity.velocity.y < entity.target_velocity.y) entity.velocity.y += 1;
        else if (entity.velocity.y > entity.target_velocity.y) entity.velocity.y -= 1;

        entity.position.x += entity.velocity.x / 4;
        resolveXCollision(entity, tilemap);
        entity.position.y += entity.velocity.y / 4;
        resolveYCollision(entity, tilemap);
    }
}