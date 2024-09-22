#include "Entity.h"
#include <iostream>

Entity::Entity(std::string name, const float init_x, const float init_y, const char origin_x, const char origin_y, const float scale_w, const float scale_h) :
    pos(init_x, init_y) {
    if (!img.loadFromFile("assets/Sprites/" + name + ".png")) {
        std::cerr << "Failed to load image for " << name << std::endl;
        return;
    }
    
    //Tex + sprite stuff
    if (!texture.loadFromImage(img)) {
        std::cerr << "Failed to load texture for " << name << std::endl;
        return;
    }
    sprite.setTexture(texture);

    //Origin (anchor) needs to be set based on IMAGE w/h before scaling is applied!
    float ori_w = img.getSize().x;
    float ori_h = img.getSize().y;
    float ori_x = 0.f;
    switch (origin_x) {
        default:
        case 'L':
            ori_x = 0.f;
            break;

        case 'C':
        case 'M':
            ori_x = ori_w * .5;
            break;

        case 'R':
            ori_x = ori_w;
            break;
    }
    float ori_y = 0.f;
    switch (origin_y) {
        default:
        case 'T':
            ori_y = 0.f;
            break;

        case 'C':
        case 'M':
            ori_y = ori_h * .5;
            break;

        case 'B':
            ori_y = ori_h;
            break;
    }
    //Set origin + scale
    sprite.setOrigin(sf::Vector2f(ori_x, ori_y));
    sprite.setScale(sf::Vector2f(scale_w, scale_h));
    sprite.setPosition(pos);

    //Set w+h
    w = ori_w * scale_w;
    h = ori_h * scale_h;
}