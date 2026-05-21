#include "components.hpp"

#define NUM_PHYSICS_ENTITY_SLOTS 16

struct PhysicsEntity {
    Position* position = nullptr;
    Dimensions* dimensions = nullptr;
    Velocity* velocity = nullptr;
    Velocity* target_velocity = nullptr;
    PhysicsEntity() = default;
    PhysicsEntity(
        Position* position,
        Dimensions* dimensions,
        Velocity* velocity,
        Velocity* target_velocity
    )
    : position(position)
    , dimensions(dimensions)
    , velocity(velocity)
    , target_velocity(target_velocity) {}
};

class PhysicsEngine{
    private:
        PhysicsEntity entity_register[NUM_PHYSICS_ENTITY_SLOTS];
        Availability available_slots[NUM_PHYSICS_ENTITY_SLOTS];
    public:
        int registerPhysicsEntity(
            Position* position,
            Dimensions* dimensions,
            Velocity* velocity,
            Velocity* target_velocity
        );
        void unregisterPhysicsEntity(int physics_entity_id);
        void simulate();
};