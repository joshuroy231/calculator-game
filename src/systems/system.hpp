#pragma once

#include "entities/entity-manager.hpp"

class System {
    protected:
        Entity* entity_registry;
        int const& num_entities;
        System(Entity* entity_registry, int const& num_entities)
        : entity_registry(entity_registry)
        , num_entities(num_entities) {}
    public:
        virtual void update() = 0;
};