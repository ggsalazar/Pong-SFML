#include "Paddle.h"

void Paddle::Move(short dir) {
    velocity += accel;
    repel = -velocity * .25;
    pos.y += velocity * dir;

    //Can't go through the top of the screen
    if (pos.y - h * .5 <= 0) {
        pos.y = h * .5;
        velocity = repel;
    }
    //Or the bottom of the screen
    else if (pos.y + h * .5 >= 720) {
        pos.y = 720 - h * .5;
        velocity = repel;
    }

    sprite.setPosition(pos);
}
