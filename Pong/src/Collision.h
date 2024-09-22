#pragma once
#include "Entity.h"

class Collision {
public:
    static bool AABB(const Entity* a, const Entity* b);
};