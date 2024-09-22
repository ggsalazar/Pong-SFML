#include "Ball.h"

Ball::Ball(std::string name, const float init_x, const float init_y, const char origin_x, const char origin_y, const float scale_w, const float scale_h) :
    Entity(name, init_x, init_y, origin_x, origin_y, scale_w, scale_h) {

    reset_pos = sf::Vector2f(init_x, init_y);

    short h_spd = min_vel + (rand() % 6);
    short v_spd = min_vel + (rand() % 6);
    if (rand() % 2) h_spd *= -1;
    if (rand() % 2) v_spd *= -1;

    velocity = sf::Vector2f(h_spd, v_spd);
}

void Ball::Move() {
    accel.x = (velocity.x < 0) ? -.01f : .01f;
    accel.y = (velocity.y < 0) ? -.01f : .01f;
    velocity += accel;
    pos += velocity;

    //Bounce off the floor/ceiling
    if (pos.y < 5.f or pos.y > 715.f)
        velocity.y *= -1;
    
    //Reset
    if (pos.x < 20.f)
        Reset(0);
    else if (pos.x > 1260.f)
        Reset(1);

    sprite.setPosition(pos);
}

void Ball::Reset(short side) {
    r_score += side;
    l_score += 1-side;

    velocity.x = min_vel + (rand() % 6);
    if (side) velocity.x *= -1;
    velocity.y = min_vel + (rand() % 6);
    if (rand() % 2) velocity.y *= -1;

    pos = reset_pos;
}
