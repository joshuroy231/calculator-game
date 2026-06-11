#include <debug.h>

#include "control-system.hpp"
#include "actuators/actuator.hpp"

ControlSystem::ControlSystem(
    Entity* entity_registry,
    int* num_entities,
    Queue<Event>* event_queue
)
: System(entity_registry, num_entities, event_queue) {}

void ControlSystem::update() {
    for (int i = 0; i < *this->num_entities; i++) {
        if (!this->entity_registry[i].profile->has_control) continue;
        entity_registry[i].actuator->actuate(entity_registry[i]);
    }
}