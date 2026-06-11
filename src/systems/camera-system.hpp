#pragma once

#include "systems/system.hpp"
#include "entities/entity.hpp"
#include "cameras/camera.hpp"

class CameraSystem : public System {
    private:
        Camera* camera = nullptr;
        Entity* entity = nullptr;
        Vec2<int> scene_dimensions;
    public:
        void follow(Entity* entity);
        void update() override;
        void initScene(Scene* scene) override;
};