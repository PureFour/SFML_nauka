
#include <iostream>
#include "../include/Snake.h"

Snake::Snake(float _x, float _y) : x(_x), y(_y)
{
    snake.setSize(sf::Vector2f(size_x, size_y));
    snake.setPosition(x, y);
    snake.setFillColor(sf::Color::Cyan);
}

Snake::~Snake() = default;

void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    target.draw(this->snake, state);
}