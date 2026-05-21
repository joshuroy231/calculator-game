#include "components.hpp"
#include "entity-configuration.hpp"

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
        Control control;

        bool has_rendering;
        bool has_physics;
        bool has_control;

        Entity() = default;
        Entity(int entity_id)
        : entity_id(entity_id) {}
};

class EntityManager {
    private:
        int num_conceived_entities = 0;
        int next_entity_id = 0;
    public:
        Entity* entity_registry;
        int num_entities = 0;
        int num_entity_registers;

        EntityManager(int num_entity_registers);

        int conceiveEntity(const EntityConfiguration entity_configuration);
        void condemnEntity(int entity_id);
        void updateEntities();
};