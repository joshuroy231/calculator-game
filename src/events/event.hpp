#pragma once

#include "entities/entity-profile.hpp"

enum class EventType {
    CONDEMN_ENTITY,
    CONCEIVE_ENTITY,
};

struct CondemnEntityEvent {
    int entity_id;
    CondemnEntityEvent(int entity_id)
    : entity_id(entity_id) {}
};
struct ConceiveEntityEvent {
    EntityConfiguration entity_configuration;
    ConceiveEntityEvent(const EntityConfiguration& entity_configuration)
    : entity_configuration(entity_configuration) {}
};

union EventData {
    CondemnEntityEvent condemn_entity;
    ConceiveEntityEvent conceive_entity;
};

class Event {
    public:
        EventType event_type;
        EventData event_data;
};