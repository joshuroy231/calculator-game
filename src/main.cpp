#include <stdint.h>

#include "rendering-engine.hpp"
#include "physics-engine.hpp"
#include "keypad.hpp"

struct Player {
    Position position;
    Dimensions dimensions;
    Velocity velocity;
    Velocity target_velocity;
    Color color;
    Player(
        Position position,
        Dimensions dimensions,
        Velocity velocity,
        Velocity target_velocity,
        Color color
    )
    : position(position)
    , dimensions(dimensions)
    , velocity(velocity)
    , target_velocity(target_velocity)
    , color(color) {}
};

int main() {
    RenderingEngine rendering_engine = RenderingEngine();
    PhysicsEngine physics_engine = PhysicsEngine();
    Keypad keypad = Keypad();

    Player player = Player(
        Position(100, 100),
        Dimensions(16, 16),
        Velocity(0, 0),
        Velocity(0, 0),
        Color(2)
    );

    rendering_engine.registerRenderingEntity(&player.position, &player.dimensions);
    physics_engine.registerPhysicsEntity(&player.position, &player.dimensions, &player.velocity, &player.target_velocity);

    KeyState* key_states;
    while (true) {
        keypad.scan();
        key_states = keypad.getKeyStates();

        int x_target_velocity = 0;
        if (key_states[LEFT] == ON || key_states[LEFT] == PRESS) x_target_velocity += 5;
        if (key_states[RIGHT] == ON || key_states[RIGHT] == PRESS) x_target_velocity -= 5;
        int y_target_velocity = 0;
        if (key_states[DOWN] == ON || key_states[DOWN] == PRESS) y_target_velocity += 5;
        if (key_states[UP] == ON || key_states[UP] == PRESS) y_target_velocity -= 5;
        player.position.x = x_target_velocity;
        player.position.y = y_target_velocity;

        physics_engine.simulate();
        rendering_engine.render();
    }
}