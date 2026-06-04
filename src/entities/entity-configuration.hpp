#pragma once

#include "entities/entity-state.hpp"
#include "entities/entity-profile.hpp"

class Actuator;
struct EntityConfiguration {
    EntityState initial_state;
    int profile_id;
    Actuator* actuator;
    EntityConfiguration() = default;
    EntityConfiguration(
        EntityState initial_state,
        int profile_id,
        Actuator* actuator
    )
    : initial_state(initial_state)
    , profile_id(profile_id)
    , actuator(actuator) {}
};