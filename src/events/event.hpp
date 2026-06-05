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

class Event {
    private:
        EventType event_type;
    public:
        EventData event_data;

        Event() = default;
        Event(CondemnEntityEvent event)
        : event_type(EventType::CONDEMN_ENTITY)
        , event_data(event) {}
        Event(ConceiveEntityEvent event)
        : event_type(EventType::CONCEIVE_ENTITY)
        , event_data(event) {}

        EventType getEventType() {
            return event_type;
        }
};