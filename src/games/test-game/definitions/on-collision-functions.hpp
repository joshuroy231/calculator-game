#pragma once

#include "entities/entity.hpp"
#include "utilities/matrix.hpp"
#include "on-collision-function.hpp"

namespace OnCollisionFunctions {
    Matrix<OnCollisionFunction>& get();
}