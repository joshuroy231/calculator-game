#include <stdbool.h>
#include <stdint.h>

#include "components.hpp"
#include "entity-manager.hpp"

class RenderingEngine {
    private:
        Entity* entity_registry;
        int const& num_entities;
    public:
        const static int WIDTH_PIXELS = 320;
        const static int HEIGHT_PIXELS = 240;

        RenderingEngine(Entity* entity_registry, int const& num_entities);
        ~RenderingEngine();
        void render();
        void renderEntities();
        void renderBackground();
};