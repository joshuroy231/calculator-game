#include "games/test-game/scenes.hpp"

namespace Scenes {
    Scene main = Scene(
        32,
        entities,
        num_entities,
        tilemap,
        Color(LIGHT_BLUE),
        Camera(Vec2<int>(0,0)),
        Vec2<int>(0, 512)
    );
}