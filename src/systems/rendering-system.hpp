#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "system.hpp"
#include "components.hpp"
#include "entities/entity-manager.hpp"

class RenderingSystem : System {
    public:
        const static int WIDTH_PIXELS = 320;
        const static int HEIGHT_PIXELS = 240;

        RenderingSystem(Entity* entity_registry, int const& num_entities);
        ~RenderingSystem();
        void update() override;
        void renderEntities();
        void renderBackground();
};