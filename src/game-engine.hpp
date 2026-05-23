#pragma once

#include "entities/entity-manager.hpp"
#include "systems/rendering-system.hpp"
#include "systems/physics-system.hpp"
#include "systems/control-system.hpp"
#include "game.hpp"

class GameEngine {
    private:
        EntityManager entity_manager;

        RenderingSystem rendering_system;
        PhysicsSystem physics_system;
        ControlSystem control_system;

        Game* game;

        void playScene(Scene* scene);
    public:
        GameEngine(Game* game);
        void playGame();
};