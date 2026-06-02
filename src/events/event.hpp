#pragma once

enum class EventType {
    TILE_COLLISION,
    ENTITY_COLLISION,
};

class Event {
    public:
        EventType event_type;
        EventData event_data;
};

union EventData {

};