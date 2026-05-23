#include <graphx.h>
#include <debug.h>

#include "rendering-system.hpp"
#include "entity-manager.hpp"

RenderingSystem::RenderingSystem(Entity* entity_registry, int const& num_entities)
: System(entity_registry, num_entities) {
    gfx_Begin();
}

RenderingSystem::~RenderingSystem() {
    gfx_End();
}

void RenderingSystem::renderEntities() {
    for (int i = 0; i < this->num_entities; i++) {
        if (!entity_registry[i].has_rendering) continue;
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

void RenderingSystem::renderBackground() {
    gfx_FillScreen(110);
}

void RenderingSystem::update() {
    this->renderBackground();
    this->renderEntities();
    gfx_SwapDraw();
}