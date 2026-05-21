#include "components.hpp"
#include "entity-manager.hpp"

#define NUM_PHYSICS_ENTITY_SLOTS 16

class PhysicsSystem {
    private:
        Entity* entity_registry;
        int const& num_entities;
    public:
        PhysicsSystem(Entity* entity_registry, int const& num_entities);
        void simulate();
};