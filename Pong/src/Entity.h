#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
    sf::Vector2f pos;
    sf::Image img;
    sf::Texture texture;
    sf::Sprite sprite;
    unsigned short w = 0;
    unsigned short h = 0;

    Entity(std::string name, const float init_x, const float init_y, const char origin_x, const char origin_y, const float scale_w, const float scale_h);

    sf::Vector2f GetScale() { return sf::Vector2f(w/img.getSize().x, h/img.getSize().y); }

};