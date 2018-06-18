
#include <iostream>
#include "../include/Snake.h"

Snake::Snake(float _x, float _y) : x(_x), y(_y)
{
    snake.setSize(sf::Vector2f(size_x, size_y));
    snake.setPosition(x, y);
    snake.setFillColor(sf::Color::Cyan);
    this->vec = sf::Vector2f(25.0, 0);
}

Snake::~Snake() = default;

void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    target.draw(this->snake, state);
}

void Snake::run()
{
    snake.move(vec);
}

const void Snake::move(const std::string &direction)
{
    if(direction == "left" && vec.x != 25.0)
    {
        this->vec = sf::Vector2f(-velocity, 0);
        return;
    }
    if(direction == "right" && vec.x == 0)
    {
        this->vec = sf::Vector2f(velocity, 0);
        return;
    }
    if(direction == "down" && vec.y == 0)
    {
        this->vec = sf::Vector2f(0, velocity);
        return;
    }
    if(direction == "up" && vec.y != 25.0)
    {
        this->vec = sf::Vector2f(0, -velocity);
        return;
    }
}

const bool Snake::check_Collisions()
{
    if(snake.getPosition().x > (Width - 25) || snake.getPosition().x < 50) return true;
    else if(snake.getPosition().y > (Height - 30) || snake.getPosition().y < 50) return true;
    return false;
}