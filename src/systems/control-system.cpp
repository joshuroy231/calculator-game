#include "control-system.hpp"

ControlSystem::ControlSystem(Entity* entity_registry, int const& num_entities)
: System(entity_registry, num_entities) {}


void ControlSystem::update() {
    for (int i = 0; i < this->num_entities; i++) {
        if (!this->entity_registry[i].has_control) continue;
        entity_registry[i].control.control(entity_registry + i);
    }
}