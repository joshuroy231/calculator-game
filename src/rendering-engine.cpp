#include "rendering-engine.hpp"
#include "entity-manager.hpp"
#include <graphx.h>

RenderingEngine::RenderingEngine() {
    gfx_Begin();
    for (int i = 0; i < NUM_RENDERING_ENTITY_SLOTS; i++) {
        this->available_slots[i] = AVAILABLE;
    }
}

RenderingEngine::~RenderingEngine() {
    gfx_End();
}

void RenderingEngine::renderRenderingEntities() {
    for (int i = 0; i < NUM_RENDERING_ENTITY_SLOTS; i++) {
        if (this->available_slots[i] == AVAILABLE) continue;
        RenderingEntity rendering_entity = this->entity_register[i];
        gfx_SetColor(rendering_entity.color->color);
        gfx_FillRectangle(
            rendering_entity.position->x,
            rendering_entity.position->y,
            rendering_entity.dimensions->w,
            rendering_entity.dimensions->h
        );
    }
}

void RenderingEngine::renderBackground() {
    gfx_FillScreen(0);
}

void RenderingEngine::render() {
    RenderingEngine::renderBackground();
    RenderingEngine::renderRenderingEntities();
}