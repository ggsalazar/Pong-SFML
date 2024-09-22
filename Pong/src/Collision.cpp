#include "Collision.h"

bool Collision::AABB(const Entity* a, const Entity* b) {
    return (a->pos.x + a->w * .5 >= b->pos.x - b->w * .5 and
            b->pos.x + b->w * .5 >= a->pos.x - a->w * .5 and
            a->pos.y + a->h * .5 >= b->pos.y - b->h * .5 and
            b->pos.y + b->h * .5 >= a->pos.y - a->h * .5);
}
