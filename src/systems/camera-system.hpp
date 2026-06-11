#pragma once

#include "systems/system.hpp"
#include "entities/entity.hpp"
#include "cameras/camera.hpp"

class CameraSystem : public System {
    private:
        Camera* camera;
        Entity* entity;
        Vec2<int> scene_dimensions;
    public:
        CameraSystem(
            Camera* camera,
            const Vec2<int> scene_dimensions
        )
        : camera(camera)
        , entity(nullptr)
        , scene_dimensions(scene_dimensions) {}
        void follow(Entity* entity);
        void update() override;
};