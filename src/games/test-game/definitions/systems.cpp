#include "games/test-game/definitions/systems.hpp"

#include "systems/control-system.hpp"
#include "systems/physics-system.hpp"
#include "systems/entity-collision-system.hpp"
#include "systems/camera-system.hpp"
#include "systems/rendering-system.hpp"
#include "games/test-game/definitions/tilemaps.hpp"
#include "utilities/enum-map.hpp"

namespace Systems {
    FixedVector<System*> init() {
        static FixedVector<System*> systems(Id::COUNT);
        systems[Id::CONTROL] = new ControlSystem();
        systems[Id::PHYSICS] = new PhysicsSystem();
        systems[Id::ENTITY_COLLISION] = new EntityCollisionSystem();
        systems[Id::CAMERA] = new CameraSystem();
        systems[Id::RENDERING] = new RenderingSystem();
        return systems;
    }
    FixedVector<System*> get() {
        static FixedVector<System*> systems = init();
        return systems;
    }
}