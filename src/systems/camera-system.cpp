#include "systems/camera-system.hpp"

void CameraSystem::follow(Entity* entity) {
    this->entity = entity;
}
void CameraSystem::update() {
    if (entity == nullptr) return;
    const Vec2<int>& e = entity->state.position;
    Vec2<int>& c = camera.position;
    if (e.x - c.x < 80) c.x = e.x - 80;
    else if (e.x - c.x > 240) c.x = e.x - 240;
    if (e.y - c.y < 60) c.y = e.y - 60;
    else if (e.y - c.y > 180) c.y = e.y - 180;

    if (c.x < 0) c.x = 0;
    else if (c.x + camera.dimensions.x > scene_dimensions.x) c.x = scene_dimensions.x - camera.dimensions.x;
    if (c.y < 0) c.y = 0;
    else if (c.y + camera.dimensions.y > scene_dimensions.y) c.y = scene_dimensions.y - camera.dimensions.y;
}