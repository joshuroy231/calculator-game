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
        System* systems;

        Game* game;
    public:
        GameEngine(Game* game);
        void playGame();
        void playScene(Scene* scene);
};