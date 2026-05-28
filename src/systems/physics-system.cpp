#include "physics-system.hpp"

PhysicsSystem::PhysicsSystem(Entity* entity_registry, int const& num_entities, Tilemap* tilemap, Vec2<int> gravity)
: System(entity_registry, num_entities)
, tilemap(tilemap)
, gravity(gravity)
{}

void resolveXCollision(Entity& entity, bool moving_right) {
    entity.state.position.x += (moving_right)
        ? -(entity.state.position.x + entity.profile->dimensions.x)%TILE_PIXELS
        : TILE_PIXELS - entity.state.position.x%TILE_PIXELS;
    entity.state.velocity.x = 0;
}
void checkXCollision(Entity& entity, Tilemap* tilemap) {
    if (entity.state.velocity.x == 0) return;
    // check left boundary collision
    if (entity.state.position.x < 0) {
        entity.state.position.x = 0;
        entity.state.velocity.x = 0;
        return;
    }
    // check right boundary collision
    if (entity.state.position.x + entity.profile->dimensions.x > tilemap->tile_dimensions.x*TILE_PIXELS) {
        entity.state.position.x = tilemap->tile_dimensions.x*TILE_PIXELS - entity.profile->dimensions.x;
        entity.state.velocity.x = 0;
        return;
    }
    int top_row = entity.state.position.y / TILE_PIXELS;
    int bottom_coord = entity.state.position.y + entity.profile->dimensions.y;
    int bottom_row = (bottom_coord % TILE_PIXELS == 0) ? (bottom_coord / TILE_PIXELS - 1) : (bottom_coord / TILE_PIXELS);
    bool moving_right = (entity.state.velocity.x > 0);
    int column = (moving_right)
        ? (entity.state.position.x + entity.profile->dimensions.x) / TILE_PIXELS
        : (entity.state.position.x) / TILE_PIXELS;
    for (int i = top_row; i <= bottom_row; i++) {
        if (tilemap->data[i*tilemap->tile_dimensions.x + column] != 0) {
            resolveXCollision(entity, moving_right);
            break;
        }
    }
}

void resolveYCollision(Entity& entity, bool moving_down) {
    entity.state.position.y += (moving_down)
        ? -(entity.state.position.y + entity.profile->dimensions.y)%TILE_PIXELS
        : TILE_PIXELS - entity.state.position.y % TILE_PIXELS;
    entity.state.velocity.y = 0;
}
void checkYCollision(Entity& entity, Tilemap* tilemap) {
    if (entity.state.velocity.y == 0) return;
    // Resolve top collision
    if (entity.state.position.y < 0) {
        entity.state.position.y = 0;
        entity.state.velocity.y = 0;
        return;
    }
    // resolve bottom collision
    if (entity.state.position.y + entity.profile->dimensions.y > tilemap->tile_dimensions.y*TILE_PIXELS) {
        entity.state.position.y = tilemap->tile_dimensions.y*TILE_PIXELS - entity.profile->dimensions.y;
        return;
    }
    int left_index = entity.state.position.x / TILE_PIXELS;
    int right_coord = entity.state.position.x + entity.profile->dimensions.x;
    int right_index = (right_coord % TILE_PIXELS == 0) ? (right_coord / TILE_PIXELS - 1) : (right_coord / TILE_PIXELS);
    bool moving_down = (entity.state.velocity.y > 0);
    int row = (moving_down)
        ? (entity.state.position.y + entity.profile->dimensions.y) / TILE_PIXELS
        : (entity.state.position.y) / TILE_PIXELS;
    for (int i = left_index; i <= right_index; i++) {
        if (tilemap->data[row*tilemap->tile_dimensions.x + i] != 0) {
            resolveYCollision(entity, moving_down);
            break;
        }
    }
}

void PhysicsSystem::update() {
    for (int i = 0; i < this->num_entities; i++) {
        if (!entity_registry[i].profile->has_physics) continue;
        Entity& entity = this->entity_registry[i];

        entity.state.velocity += this->gravity/FPS;
        entity.state.velocity += entity.state.acceleration/FPS;

        int& v = entity.state.velocity.x;
        if (v != 0) {
            int decay = v / 5;

            if (decay != 0) {
                v -= decay;
            } else {
                v -= (v > 0) ? 1 : -1;
            }
        }

        if (entity.state.velocity.x > entity.profile->terminal_velocity_x) entity.state.velocity.x = entity.profile->terminal_velocity_x;
        else if (entity.state.velocity.x < -entity.profile->terminal_velocity_x) entity.state.velocity.x = -entity.profile->terminal_velocity_x;
        if (entity.state.velocity.y > entity.profile->terminal_velocity_y) entity.state.velocity.y = entity.profile->terminal_velocity_y;
        else if (entity.state.velocity.y < -entity.profile->terminal_velocity_y) entity.state.velocity.y = -entity.profile->terminal_velocity_y;

        entity.state.position.x += entity.state.velocity.x / FPS;
        checkXCollision(entity, tilemap);
        entity.state.position.y += entity.state.velocity.y / FPS;
        checkYCollision(entity, tilemap);
    }
}