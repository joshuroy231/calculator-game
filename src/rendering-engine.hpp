#include <stdbool.h>
#include <stdint.h>

#include "components.hpp"

#define NUM_RENDERING_ENTITY_SLOTS 16
#define ENTITY_REGISTER_FULL -1

class EntityManager;

class RenderingEngine {
    private:
        EntityManager* entity_manager;
    public:
        const static int WIDTH_PIXELS = 320;
        const static int HEIGHT_PIXELS = 240;

        RenderingEngine(EntityManager* entity_manager)
        : entity_manager(entity_manager) {}
        ~RenderingEngine();
        void render();
        void renderRenderingEntities();
        void renderBackground();
};