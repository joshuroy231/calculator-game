#pragma once

#include "events/event-data.hpp"

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