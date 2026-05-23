#include <graphx.h>
#include <debug.h>

#include "rendering-system.hpp"

RenderingSystem::RenderingSystem(
    Entity* entity_registry,
    int const& num_entities,
    Tilemap* tilemap,
    Color background_color
)
: System(entity_registry, num_entities)
, tilemap(tilemap)
, background_color(background_color)
{
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
    gfx_FillScreen(background_color.color);
}

void RenderingSystem::renderTiles() {
    gfx_SetColor(255);
    for (int i = 0; i < tilemap->num_rows; i++) {
        for (int j = 0; j < tilemap->num_cols; j++) {
            if (tilemap->data[tilemap->num_cols*i + j] == 1) {
                gfx_FillRectangle(
                    j*TILE_PIXELS,
                    i*TILE_PIXELS,
                    TILE_PIXELS,
                    TILE_PIXELS
                );
            }
        }
    }
}

void RenderingSystem::update() {
    this->renderBackground();
    this->renderTiles();
    this->renderEntities();
    gfx_SwapDraw();
}