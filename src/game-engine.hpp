#pragma once

#include "entity-manager.hpp"
#include "rendering-engine.hpp"
#include "physics-engine.hpp"

class GameEngine {
    private:
        EntityManager entity_manager;

        RenderingEngine rendering_engine;
        PhysicsEngine physics_engine;
    public:
};