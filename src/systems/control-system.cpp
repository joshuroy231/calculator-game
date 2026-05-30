#include <debug.h>

#include "control-system.hpp"

ControlSystem::ControlSystem(Entity* entity_registry, int const& num_entities)
: System(entity_registry, num_entities) {}


void ControlSystem::update() {
    dbg_printf("There are %d entities\n", this->num_entities);
    for (int i = 0; i < this->num_entities; i++) {
        dbg_printf("On loop %d\n", i);
        if (!this->entity_registry[i].profile->has_control) continue;
        entity_registry[i].profile->control.actuator->actuate(entity_registry[i]);
    }
}