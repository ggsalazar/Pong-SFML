#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Entity.h"
#include "Ball.h"
#include "Paddle.h"
#include "Collision.h"

int main() {
    float win_w = 1280.f;
    float win_h = 720.f;

    sf::RenderWindow window(sf::VideoMode(win_w, win_h), "Pong SFML");
    window.setFramerateLimit(60);

    std::vector<Entity*> entities;
   
    //Ball
    Ball* ball = new Ball("Ball", win_w * .5, win_h * .5, 'C', 'C', 2.f, 2.f);
    entities.push_back(ball);

    //Paddles
    //Left paddle
    Paddle* l_paddle = new Paddle("L_Paddle", win_w * .04, win_h*.5, 'C', 'C', 1.f, 4.f);
    entities.push_back(l_paddle);
    //Right paddle
    Paddle* r_paddle = new Paddle("R_Paddle", win_w * .96, win_h * .5, 'C', 'C', 1.f, 4.f);
    entities.push_back(r_paddle);

    //Scores
    sf::Font score_font;
    if (!score_font.loadFromFile("assets/Fonts/m5x7.ttf")) return 0;
    //Left score
    sf::Text l_score;
    l_score.setFont(score_font);
    l_score.setCharacterSize(48);
    l_score.setPosition(sf::Vector2f(win_w * .4, win_h * .1));
    //Right score
    sf::Text r_score = l_score;
    r_score.setPosition(sf::Vector2f(win_w * .6, win_h * .1));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                   window.close();
        }
        
        //Move the paddles
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            l_paddle->Move(-1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            l_paddle->Move(1);
        else
            l_paddle->velocity = 6;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            r_paddle->Move(-1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            r_paddle->Move(1);
        else
            r_paddle->velocity = 6;

        //Move the ball
        ball->Move();
        //Bounce the ball
        if (Collision::AABB(ball, l_paddle)) {
            ball->pos.x = win_w*.05;
            ball->Bounce();
        }
        else if (Collision::AABB(ball, r_paddle)) {
            ball->pos.x = win_w*.95;
            ball->Bounce();
        }

        //Set the scores
        l_score.setString(std::to_string(ball->l_score));
        r_score.setString(std::to_string(ball->r_score));
        l_score.setFillColor(sf::Color::White);
        r_score.setFillColor(sf::Color::White);
        if (ball->l_score > ball->r_score) {
            l_score.setFillColor(sf::Color::Green);
            r_score.setFillColor(sf::Color::Red);
        }
        else if (ball->l_score < ball->r_score) {
            l_score.setFillColor(sf::Color::Red);
            r_score.setFillColor(sf::Color::Green);
        }

        //Draw the entities
        window.clear();
        for (Entity* e : entities)
            window.draw(e->sprite);

        //Draw the scores
        window.draw(l_score);
        window.draw(r_score);

        window.display();
    }

    return 0;
}