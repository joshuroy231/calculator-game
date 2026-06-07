#include "games/test-game/scenes.hpp"
#include "games/test-game/definitions/tilemaps.hpp"
#include "games/test-game/definitions/entity-profiles.hpp"
#include "games/test-game/definitions/actuators.hpp"
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
                EntityProfiles::Id::PLAYER,
                Actuators::get()
            ),
            EntityConfiguration(
                EntityState(
                    Vec2<int>(32, 170),
                    Vec2<int>(),
                    Vec2<int>()
                ),
                EntityProfiles::Id::MYSTERY_BOX,
                nullptr
            ),
            EntityConfiguration(
                EntityState(
                    Vec2<int>(128, 32),
                    Vec2<int>(),
                    Vec2<int>()
                ),
                EntityProfiles::Id::GOOMBA,
                Actuators::get()
            )
        };

        static Scene* main_scene = new Scene(
            initial_entities,
            sizeof(initial_entities) / sizeof(EntityConfiguration),
            Tilemaps::get()[Tilemaps::Id::MAIN],
            LIGHT_BLUE,
            Camera(Vec2<int>(0,0)),
            Vec2<int>(0, 512)
        );

        return main_scene;
    }
}