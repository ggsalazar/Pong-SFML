#pragma once
#include "Entity.h"

class Ball : public Entity {
public:
    unsigned short l_score = 0;
    unsigned short r_score = 0;

    Ball(std::string name, const float init_x, const float init_y, const char origin_x, const char origin_y, const float scale_w, const float scale_h);

    void Move();
    void Bounce() { velocity.x *= -1.f; }

private:
    sf::Vector2f accel = sf::Vector2f(.01f, .01f);
    sf::Vector2f velocity;
    sf::Vector2f reset_pos;
    unsigned short min_vel = 3;

    void Reset(short side);
};