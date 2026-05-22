#include <graphx.h>

#include "rendering-system.hpp"

RenderingSystem::RenderingSystem(
    Entity* entity_registry,
    int const& num_entities,
    Tilemap* tilemap
)
: System(entity_registry, num_entities)
, tilemap(tilemap) {
    gfx_Begin();
}

RenderingSystem::~RenderingSystem() {
    gfx_End();
}

void RenderingSystem::renderEntities() {
    for (int i = 0; i < this->num_entities; i++) {
        if (!entity_registry[i].entity_profile->has_rendering) continue;
        Entity entity = this->entity_registry[i];
        gfx_SetColor(entity.entity_profile->color.color);
        gfx_FillRectangle(
            entity.position.x,
            entity.position.y,
            entity.entity_profile->dimensions.w,
            entity.entity_profile->dimensions.h
        );
    }
}

void RenderingSystem::renderBackground() {
    gfx_FillScreen(0);
}

void RenderingSystem::renderTiles() {
    gfx_SetColor(255);
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            if (tilemap->data[20*i + j] == 1) {
                gfx_FillRectangle(
                    j*16,
                    i*16,
                    16,
                    16
                );
            }
        }
    }
}

void RenderingSystem::update() {
    this->renderBackground();
    this->renderTiles();
    this->renderEntities();
}