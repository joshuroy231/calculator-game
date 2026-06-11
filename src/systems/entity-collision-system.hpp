#pragma once

#include "systems/system.hpp"
#include "events/event.hpp"
#include "utilities/queue.hpp"
#include "on-collision-function.hpp"
#include "utilities/matrix.hpp"


class EntityCollisionSystem : public System {
    private:
        Matrix<OnCollisionFunction>* collision_matrix = nullptr;
    public:
        void update() override;
        void initGame(Game* game) override;
};