#pragma once

#include "entities/entity-profile.hpp"
#include "entities/entity-configuration.hpp"

enum class EventType {
    CONDEMN_ENTITY,
    CONCEIVE_ENTITY,
};

struct CondemnEntityEvent {
    int id;
    CondemnEntityEvent() = default;
    CondemnEntityEvent(int id)
    : id(id) {}
};
struct ConceiveEntityEvent {
    EntityConfiguration entity_configuration;
    ConceiveEntityEvent() = default;
    ConceiveEntityEvent(const EntityConfiguration& entity_configuration)
    : entity_configuration(entity_configuration) {}
};

union EventData {
    CondemnEntityEvent condemn_entity;
    ConceiveEntityEvent conceive_entity;

    EventData() = default;
    EventData(CondemnEntityEvent event)
    : condemn_entity(event) {}
    EventData(ConceiveEntityEvent event)
    : conceive_entity(event) {}
};