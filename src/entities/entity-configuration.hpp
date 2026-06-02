#pragma once

#include "entities/entity-state.hpp"
#include "entities/entity-profile.hpp"

class Actuator;
struct EntityConfiguration {
    EntityState initial_state;
    const EntityProfile* profile;
    Actuator* actuator;
    EntityConfiguration(
        const EntityState initial_state,
        const EntityProfile* profile,
        Actuator* actuator
    )
    : initial_state(initial_state)
    , profile(profile)
    , actuator(actuator) {}
};