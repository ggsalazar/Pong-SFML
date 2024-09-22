#pragma once
#include "Entity.h"

class Paddle : public Entity {
public:
    float velocity = 6;

    Paddle(std::string name, const float init_x, const float init_y, const char origin_x, const char origin_y, const float scale_w, const float scale_h) :
        Entity(name, init_x, init_y, origin_x, origin_y, scale_w, scale_h) {}

    void Move(short dir);

private:
    float accel = .125f;
    float repel = 0.f;
};
