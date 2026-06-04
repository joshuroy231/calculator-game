#pragma once

#include "entities/entity.hpp"

using OnCollisionFunction = void(*)(Entity&, const Entity&);

namespace OnCollisionFunctions {
    OnCollisionFunction* get();
}