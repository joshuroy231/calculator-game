#pragma once

#include "system.hpp"
#include "entities/entity.hpp"
#include "tilemap.hpp"

class PhysicsSystem : public System {
    private:
        Tilemap* tilemap = nullptr;
        Vec2<int> gravity;
    public:
        PhysicsSystem() = default;
        void update() override;
        void initScene(Scene* scene) override;
};