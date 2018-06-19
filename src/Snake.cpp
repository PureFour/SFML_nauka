
#include <iostream>
#include "../include/Snake.h"

Snake::Snake(float _x, float _y) : x(_x), y(_y)
{
    snake.setSize(sf::Vector2f(size_x, size_y));
    snake.setPosition(x, y);
    snake.setFillColor(sf::Color::Cyan);
   // snake.setOrigin(12.5, 12.5);
    this->vec = sf::Vector2f(25.0, 0);
    this->score = 0;
}

Snake::~Snake() = default;

void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    target.draw(this->snake, state);
}

unsigned int& Snake::getScore() { return this->score; }

void Snake::run()
{
    snake.move(vec);
}

const void Snake::move(const std::string &direction)
{
    if(direction == "left" && vec.x != velocity)
    {
        this->vec.x = -velocity;
        this->vec.y = 0;
        return;
    }
    if(direction == "right" && vec.x == 0)
    {
        this->vec.x = velocity;
        this->vec.y = 0;
        return;
    }
    if(direction == "down" && vec.y == 0)
    {
        this->vec.x = 0;
        this->vec.y = velocity;
        return;
    }
    if(direction == "up" && vec.y != velocity)
    {
        this->vec.x = 0;
        this->vec.y = -velocity;
        return;
    }
}

const bool Snake::check_Collisions()
{
    if(snake.getPosition().x > (Width - velocity) || snake.getPosition().x < 0) return true;
    else if(snake.getPosition().y > (Height - velocity) || snake.getPosition().y < 0) return true;
    return false;
}

const bool Snake::eatFood(const sf::RectangleShape &food)
{
    if(snake.getPosition().x == food.getPosition().x && snake.getPosition().y == food.getPosition().y)
    {
        std::cout << "Eating food...\n";
        score += 1;

        return true;
    }
    return false;
}

void Snake::snake_elongate()
{

}