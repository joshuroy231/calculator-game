#include "entity-configuration.hpp"

class Scene {
    public:
        int entity_pool_size;
        EntityConfiguration* initial_entities;
        int num_initial_entities;
};
class Game {
    public:
        Scene* scene;
};