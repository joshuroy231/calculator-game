#pragma once

#include "systems/system.hpp"
#include "entities/entity.hpp"
#include "cameras/camera.hpp"

class CameraSystem : public System {
    private:
        Camera* camera = nullptr;
        Entity* entity = nullptr;
        Vec2<int> scene_dimensions;
        void follow(int entity_id);
    public:
        void update() override;
        void consumeEvents() override;
        void initScene(Scene* scene) override;
};