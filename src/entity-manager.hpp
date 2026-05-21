#include "components.hpp"

class Entity {
    friend class EntityManager;
    private:
        bool is_condemned = false;
        int entity_id;
    public:
        Position position;
        Dimensions dimensions;
        Velocity velocity;
        Velocity target_velocity;
        Color color;

        bool is_rendering_entity;
        bool is_physics_entity;

        Entity() = default;
        Entity(int entity_id)
        : entity_id(entity_id) {}
};

class EntityManager {
    private:
        int num_conceived_entities = 0;
        int next_entity_id = 0;
        Entity* entity_registry;
    public:
        int num_entities = 0;
        int num_entity_registers;

        EntityManager(int num_entity_registers);

        int conceiveEntity(const EntityConfiguration entity_configuration);
        void condemnEntity(int entity_id);
        void updateEntities();
};

struct EntityConfiguration {
        Position position;
        Dimensions dimensions;
        Velocity velocity;
        Velocity target_velocity;
        Color color;
        bool is_rendering_entity = false;
        bool is_physics_entity = false;
};