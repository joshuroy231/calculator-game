#include <graphx.h>
#include <debug.h>

#include "rendering-system.hpp"

RenderingSystem::RenderingSystem(
    Entity* entity_registry,
    int const& num_entities,
    Tilemap* tilemap,
    Color background_color,
    const Vec2<int>& camera_position
)
: System(entity_registry, num_entities)
, tilemap(tilemap)
, background_color(background_color)
, camera_position(camera_position)
{
    gfx_Begin();
}

RenderingSystem::~RenderingSystem() {
    gfx_End();
}

void RenderingSystem::renderEntities() {
    for (int i = 0; i < this->num_entities; i++) {
        if (!entity_registry[i].profile->has_rendering) continue;
        Entity& entity = this->entity_registry[i];
        gfx_SetColor(entity.profile->color.color);
        gfx_FillRectangle(
            entity.state.position.x - camera_position.x,
            entity.state.position.y - camera_position.y,
            entity.profile->dimensions.x,
            entity.profile->dimensions.y
        );
    }
}

void RenderingSystem::renderBackground() {
    gfx_FillScreen(background_color.color);
}

void RenderingSystem::renderTiles() {
    for (int i = 0; i < tilemap->tile_dimensions.y; i++) {
        for (int j = camera_position.x/TILE_PIXELS; j < (camera_position.x + 336)/TILE_PIXELS; j++) {
            int tile_value = tilemap->data[tilemap->tile_dimensions.x*i + j];
            if (tile_value == 0) continue;
            gfx_SetColor(tilemap->tile_types[tile_value].color.color);
            gfx_FillRectangle(
                j*TILE_PIXELS - camera_position.x,
                i*TILE_PIXELS - camera_position.y,
                TILE_PIXELS,
                TILE_PIXELS
            );
        }
    }
}

void RenderingSystem::update() {
    this->renderBackground();
    this->renderTiles();
    this->renderEntities();
    gfx_SwapDraw();
}