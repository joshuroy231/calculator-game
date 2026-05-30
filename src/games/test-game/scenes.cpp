#include "games/test-game/scenes.hpp"
#include "games/test-game/definitions/tilemaps.hpp"
#include "games/test-game/definitions/entity-profiles.hpp"
#include "cameras/camera.hpp"

namespace Scenes {
    Scene* get() {
        static EntityConfiguration initial_entities[] = {
            EntityConfiguration(
                EntityState(
                    Vec2<int>(32, 32),
                    Vec2<int>(),
                    Vec2<int>()
                ),
                EntityProfiles::get(EntityProfiles::Id::PLAYER)
            ),
            EntityConfiguration(
                EntityState(
                    Vec2<int>(32, 128),
                    Vec2<int>(),
                    Vec2<int>()
                ),
                EntityProfiles::get(EntityProfiles::Id::MYSTERY_BOX)
            )
        };

        static Scene* main_scene = new Scene(
            32,
            initial_entities,
            sizeof(initial_entities) / sizeof(EntityConfiguration),
            Tilemaps::get(),
            Color(LIGHT_BLUE),
            Camera(Vec2<int>(0,0)),
            Vec2<int>(0, 512)
        );

        return main_scene;
    }
}

