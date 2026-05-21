#pragma once

#include "entity-manager.hpp"
#include "rendering-system.hpp"
#include "physics-system.hpp"
#include "game.hpp"

class Gamesystem {
    private:
        EntityManager entity_manager;

        RenderingSystem rendering_system;
        PhysicsSystem physics_system;

        Game* game;
    public:
        Gamesystem(Game* game);
        void playGame();
        void playScene(Scene* scene);
};