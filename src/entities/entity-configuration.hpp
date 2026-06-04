#pragma once

#include "entities/entity-state.hpp"
#include "entities/entity-profile.hpp"

class Actuator;
struct EntityConfiguration {
    EntityState initial_state;
    EntityProfile* profile;
    Actuator* actuator;
    EntityConfiguration() = default;
    EntityConfiguration(
        EntityState initial_state,
        EntityProfile* profile,
        Actuator* actuator
    )
    : initial_state(initial_state)
    , profile(profile)
    , actuator(actuator) {}
};