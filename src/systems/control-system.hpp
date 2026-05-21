#include "system.hpp"

class ControlSystem : System {
    public:
        ControlSystem(Entity* entity_registry, int const& num_entities);
        void update() override;
};