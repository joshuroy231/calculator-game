#pragma once

#include "entities/entity.hpp"
#include "utilities/matrix.hpp"
#include "systems/entity-collision-system.hpp"

namespace OnCollisionFunctions {
    Matrix<OnCollisionFunction>& get();
}