#include "system.hpp"
#include "components.hpp"
#include "entity-manager.hpp"

class PhysicsSystem : System {
    public:
        PhysicsSystem(Entity* entity_registry, int const& num_entities);
        void update() override;
};