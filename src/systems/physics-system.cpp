#include "physics-system.hpp"

PhysicsSystem::PhysicsSystem(Entity* entity_registry, int const& num_entities, Tilemap* tilemap)
: System(entity_registry, num_entities)
, tilemap(tilemap)
{}

void resolveXCollision(Entity& entity, bool moving_right) {
    entity.position.x += (moving_right)
        ? -entity.position.x%TILE_PIXELS
        : TILE_PIXELS - entity.position.x%TILE_PIXELS;
    entity.velocity.x = 0;
}
void checkXCollision(Entity& entity, Tilemap* tilemap) {
    if (entity.velocity.x == 0) return;
    // check left boundary collision
    if (entity.position.x < 0) {
        entity.position.x = 0;
        entity.velocity.x = 0;
        return;
    }
    // check right boundary collision
    if (entity.position.x + entity.entity_profile->dimensions.w > tilemap->num_cols*TILE_PIXELS) {
        entity.position.x = tilemap->num_cols*TILE_PIXELS - entity.entity_profile->dimensions.w;
        entity.velocity.x = 0;
        return;
    }
    int top_row = entity.position.y / TILE_PIXELS;
    int bottom_coord = entity.position.y + entity.entity_profile->dimensions.h;
    int bottom_row = (bottom_coord % TILE_PIXELS == 0) ? (bottom_coord / TILE_PIXELS - 1) : (bottom_coord / TILE_PIXELS);
    bool moving_right = (entity.velocity.x > 0);
    int column = (moving_right)
        ? (entity.position.x + entity.entity_profile->dimensions.w) / TILE_PIXELS
        : (entity.position.x) / TILE_PIXELS;
    for (int i = top_row; i <= bottom_row; i++) {
        if (tilemap->data[i*tilemap->num_cols + column] != 0) {
            resolveXCollision(entity, moving_right);
            break;
        }
    }
}

void resolveYCollision(Entity& entity, bool moving_down) {
    entity.position.y += (moving_down)
        ? -entity.position.y%TILE_PIXELS
        : TILE_PIXELS - entity.position.y % TILE_PIXELS;
    entity.velocity.y = 0;
}
void checkYCollision(Entity& entity, Tilemap* tilemap) {
    if (entity.velocity.y == 0) return;
    // Resolve top collision
    if (entity.position.y < 0) {
        entity.position.y = 0;
        entity.velocity.y = 0;
        return;
    }
    // resolve bottom collision
    if (entity.position.y + entity.entity_profile->dimensions.h > tilemap->num_rows*TILE_PIXELS) {
        entity.position.y = tilemap->num_rows*TILE_PIXELS - entity.entity_profile->dimensions.h;
        return;
    }
    int left_index = entity.position.x / TILE_PIXELS;
    int right_coord = entity.position.x + entity.entity_profile->dimensions.w;
    int right_index = (right_coord % TILE_PIXELS == 0) ? (right_coord / TILE_PIXELS - 1) : (right_coord / TILE_PIXELS);
    bool moving_down = (entity.velocity.y > 0);
    int row = (moving_down)
        ? (entity.position.y + entity.entity_profile->dimensions.h) / TILE_PIXELS
        : (entity.position.y) / TILE_PIXELS;
    for (int i = left_index; i <= right_index; i++) {
        if (tilemap->data[row*tilemap->num_cols + i] != 0) {
            resolveYCollision(entity, moving_down);
            break;
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
        checkXCollision(entity, tilemap);
        entity.position.y += entity.velocity.y / 4;
        checkYCollision(entity, tilemap);
    }
}