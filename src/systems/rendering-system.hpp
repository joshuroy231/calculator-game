#pragma once

#include "system.hpp"
#include "entities/entity.hpp"
#include "tilemap.hpp"

class RenderingSystem : public System {
    private:
        Tilemap* tilemap = nullptr;
        uint8_t background_color;
        Vec2<int>* camera_position = nullptr;
    public:
        RenderingSystem() = default;
        ~RenderingSystem();
        void update() override;
        void initScene(Scene* scene) override;
        void initGame(Game* game) override;
        void renderBackground();
        void renderTiles();
        void renderEntities();
};