#include "entity-configuration.hpp"

class Scene {
    public:
        int entity_pool_size;
        EntityConfiguration* initial_entities;
        int num_initial_entities;
        Scene(int entity_pool_size, EntityConfiguration* initial_entities, num_initial_entities)
        : entity_pool_size(entity_pool_size)
        , initial_entities(initial_entities)
        , num_initial_entities(num_initial_entities) {}
};
class Game {
    public:
        Scene* scene;
        Game(Scene* scene)
        : scene(scene) {}
};