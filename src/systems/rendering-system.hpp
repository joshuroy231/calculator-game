#include <stdbool.h>
#include <stdint.h>

#include "components.hpp"
#include "entity-manager.hpp"

class RenderingSystem {
    private:
        Entity* entity_registry;
        int const& num_entities;
    public:
        const static int WIDTH_PIXELS = 320;
        const static int HEIGHT_PIXELS = 240;

        RenderingSystem(Entity* entity_registry, int const& num_entities);
        ~RenderingSystem();
        void render();
        void renderEntities();
        void renderBackground();
};