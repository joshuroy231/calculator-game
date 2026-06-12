#include "physics-system.hpp"

#include "scene.hpp"

void resolveCollision(Entity& entity, bool moving_down, Component c) {
    entity.state.position[c] += (moving_down)
        ? -(entity.state.position[c] + entity.profile->dimensions[c])%TILE_PIXELS
        : TILE_PIXELS - entity.state.position[c] % TILE_PIXELS;
    entity.state.velocity[c] = 0;
}
void checkCollision(Entity& entity, Tilemap* tilemap, Component c) {
    if (entity.state.velocity[c] == 0) return;

    if (entity.state.position[c] < 0) {
        entity.state.position[c] = 0;
        entity.state.velocity[c] = 0;
        return;
    }

    if (entity.state.position[c] + entity.profile->dimensions[c] > tilemap->tile_dimensions[c]*TILE_PIXELS) {
        entity.state.position[c] = tilemap->tile_dimensions[c]*TILE_PIXELS - entity.profile->dimensions[c];
        return;
    }
    int left_index = entity.state.position.x / TILE_PIXELS;
    int right_coord = entity.state.position.x + entity.profile->dimensions.x;
    int right_index = (right_coord % TILE_PIXELS == 0) ? (right_coord / TILE_PIXELS - 1) : (right_coord / TILE_PIXELS);
    bool moving_down = (entity.state.velocity[c] > 0);
    int row = (moving_down)
        ? (entity.state.position[c] + entity.profile->dimensions[c]) / TILE_PIXELS
        : (entity.state.position[c]) / TILE_PIXELS;
    for (int i = left_index; i <= right_index; i++) {
        if (tilemap->data[row*tilemap->tile_dimensions.x + i] != 0) {
            resolveCollision(entity, moving_down, c);
            break;
        }
    }
}

void PhysicsSystem::update() {
    for (int i = 0; i < *this->num_entities; i++) {
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
        checkCollision(entity, tilemap, Component::X);
        entity.state.position.y += entity.state.velocity.y / FPS;
        checkCollision(entity, tilemap, Component::Y);
    }
}

void PhysicsSystem::initScene(Scene* scene) {
    this->tilemap = &scene->tilemap;
    this->gravity = scene->gravity;
}