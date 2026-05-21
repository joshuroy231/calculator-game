#include <graphx.h>

#include "rendering-engine.hpp"
#include "entity-manager.hpp"

RenderingEngine::RenderingEngine(Entity* entity_registry, int const& num_entities)
: num_entities(num_entities) {
    this->entity_registry = entity_registry;
    gfx_Begin();
}

RenderingEngine::~RenderingEngine() {
    gfx_End();
}

void RenderingEngine::renderEntities() {
    for (int i = 0; i < this->num_entities; i++) {
        Entity entity = this->entity_registry[i];
        gfx_SetColor(entity.color.color);
        gfx_FillRectangle(
            entity.position.x,
            entity.position.y,
            entity.dimensions.w,
            entity.dimensions.h
        );
    }
}

void RenderingEngine::renderBackground() {
    gfx_FillScreen(0);
}

void RenderingEngine::render() {
    this->renderBackground();
    this->renderEntities();
}