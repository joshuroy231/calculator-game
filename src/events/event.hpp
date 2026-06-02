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

    EventData(CondemnEntityEvent event)
    : condemn_entity(event) {}
    EventData(ConceiveEntityEvent event)
    : conceive_entity(event) {}
};

class Event {
    private:
        EventType event_type;
    public:
        EventData event_data;

        Event(CondemnEntityEvent event)
        : event_type(EventType::CONDEMN_ENTITY)
        , event_data(event) {}
        Event(CondemnEntityEvent event)
        : event_type(EventType::CONCEIVE_ENTITY)
        , event_data(event) {}

        EventType getEventType() {
            return event_type;
        }
};