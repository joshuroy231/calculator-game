#include "components.hpp"
#include "entity-manager.hpp"

#define NUM_PHYSICS_ENTITY_SLOTS 16

class PhysicsEngine {
    private:
        Entity* entity_registry;
        int const& num_entities;
    public:
        PhysicsEngine(Entity* entity_registry, int const& num_entities);
        void simulate();
};