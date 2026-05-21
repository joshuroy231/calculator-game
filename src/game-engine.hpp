#pragma once

#include "entity-manager.hpp"
#include "rendering-system.hpp"
#include "physics-system.hpp"
#include "game.hpp"

class GameEngine {
    private:
        EntityManager entity_manager;

        RenderingSystem rendering_system;
        PhysicsSystem physics_system;

        Game* game;

        void playScene(Scene* scene);
    public:
        GameEngine(Game* game);
        void playGame();
};