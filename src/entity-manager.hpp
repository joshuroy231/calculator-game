#include "components.hpp"

class Entity {
    Component* components[NUM_COMPONENTS];
}

class Entity {
    friend class EntityManager;
    private:
        int entity_id;
    public:
        Position* position = nullptr;
        Dimensions* dimensions = nullptr;
        Velocity* velocity = nullptr;
        Velocity* target_velocity = nullptr;
        Color* color = nullptr;

        Entity() = default;
        Entity(int entity_id)
        : entity_id(entity_id) {}
};

class EntityManager {
    private:
        int next_entity_id = 0;
        Entity* entity_registry;
    public:
        int num_entities;
        int num_entity_registers;

        EntityManager(int num_entity_registers);
        int registerEntity();
        void unregisterEntity(int entity_id);
        Entity* getEntity(int entity_id);
        Entity* getEntities();
        class Builder {
            
        };
};

class EntityBuilder {
    private:
        EntityManager* entity_manager;        

        Position position;
        Dimensions dimensions;
        Velocity velocity;
        Velocity target_velocity;
        Color color;

        bool is_rendering_entity = false;
        bool is_physics_entity = false;

    public:
        EntityBuilder* setPosition(Position position);
        EntityBuilder* setDimensions(Dimensions dimensions);
        EntityBuilder* setVelocity(Velocity velocity);
        EntityBuilder* setTargetVelocity(Velocity target_velocity);
        EntityBuilder* setColor(Color color);

        EntityBuilder* setAsRenderingEntity();
        EntityBuilder* setAsPhysicsEntity();

        int registerEntity();
}