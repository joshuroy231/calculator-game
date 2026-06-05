#pragma once

#include "entities/entity-manager.hpp"
#include "systems/rendering-system.hpp"
#include "systems/physics-system.hpp"
#include "systems/control-system.hpp"
#include "systems/entity-collision-system.hpp"
#include "systems/camera-system.hpp"
#include "keypad.hpp"
#include "utilities/queue.hpp"
#include "events/event.hpp"
#include "game.hpp"

class GameEngine {
    private:
        Queue<Event> event_queue;

        EntityManager entity_manager;

        RenderingSystem rendering_system;
        PhysicsSystem physics_system;
        ControlSystem control_system;
        EntityCollisionSystem entity_collision_system;
        CameraSystem camera_system;

        Keypad* keypad;

        Game* game;

        void playScene(Scene* scene);
    public:
        GameEngine(Game* game);
        void registerKeypad(Keypad* keypad);
        void playGame();
};