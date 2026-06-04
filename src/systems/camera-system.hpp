#pragma once

#include "systems/system.hpp"
#include "entities/entity.hpp"
#include "cameras/camera.hpp"

class CameraSystem : System {
    private:
        Camera& camera;
        Entity* entity;
        Vec2<int> scene_dimensions;
    public:
        CameraSystem(Entity* entity_registry, const int& num_entities, Camera& camera, const Vec2<int> scene_dimensions)
        : System(entity_registry, num_entities)
        , camera(camera)
        , entity(nullptr)
        , scene_dimensions(scene_dimensions) {}
        void follow(Entity* entity);
        void update() override;
};