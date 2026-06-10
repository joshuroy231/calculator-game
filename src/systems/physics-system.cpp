#include "physics-system.hpp"

#include "utilities/helpers.hpp"

PhysicsSystem::PhysicsSystem(
    Entity* entity_registry,
    int const& num_entities,
    Queue<Event>& event_queue,
    Tilemap* tilemap,
    Vec2<int> gravity
)
: System(entity_registry, num_entities, event_queue)
, tilemap(tilemap)
, gravity(gravity)
{}

void PhysicsSystem::update() {
    for (int i = 0; i < this->num_entities; i++) {
        if (!entity_registry[i].profile->has_physics) continue;
        Entity& entity = this->entity_registry[i];
        Vec2<int>& p = entity.state.position;
        Vec2<int>& v = entity.state.velocity;

        v += this->gravity/FPS;
        v += entity.state.acceleration/FPS;

        if (v.x != 0) {
            int decay = v.x / 5;

            if (decay != 0) v.x -= decay;
            else v.x -= (v.x > 0) ? 1 : -1;
        }

        if (v.x > entity.profile->terminal_velocity_x) v.x = entity.profile->terminal_velocity_x;
        else if (v.x < -entity.profile->terminal_velocity_x) v.x = -entity.profile->terminal_velocity_x;
        if (v.y > entity.profile->terminal_velocity_y) v.y = entity.profile->terminal_velocity_y;
        else if (v.y < -entity.profile->terminal_velocity_y) v.y = -entity.profile->terminal_velocity_y;

        p += v / FPS;

        Box<int> entity_box = Box<int>(p, entity.profile->dimensions);
        for (int i = entity_box.x_min / TILE_PIXELS; i <= entity_box.x_max / TILE_PIXELS; i++) {
            for (int j = entity_box.y_min / TILE_PIXELS; j <= entity_box.y_max / TILE_PIXELS; j++) {
                Box<int> tile_box = Box<int>(i*TILE_PIXELS, j*TILE_PIXELS, (i+1)*TILE_PIXELS, (j+1)*TILE_PIXELS);
                if (tilemap->data[j*tilemap->tile_dimensions.x + i] == 0) continue;
                Vec2<int> collision = getCollision(entity_box, v, tile_box, Vec2<int>(0, 0));
                p += collision;
                if (collision.x != 0) v.x = 0;
                if (collision.y != 0) v.y = 0;
                goto collision_resolved;
            }
        }
        collision_resolved:;
    }
}