#include <iostream>
#include "../include/Snake.h"

Snake::Snake(float _x, float _y) : x(_x), y(_y)
{
    //segment initialize
    snake_segment.setSize(sf::Vector2f(size_x, size_y));
    snake_segment.setPosition(x, y);
    snake_segment.setFillColor(sf::Color::Cyan);
    snake.push_back(snake_segment);
    this->vec = sf::Vector2f(25.0, 0);
    this->score = 0;
}

Snake::~Snake() = default;

void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    for(const auto &i : snake)
        target.draw(i, state);
}

unsigned int& Snake::getScore() { return this->score; }

void Snake::run()
{
    snake.front().move(vec);
    for(int i = 1; i < snake.size(); i++)
        snake[i].setPosition(snake[i-1].getPosition() - vec);
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
    if(snake.front().getPosition().x > (Width - velocity) || snake.front().getPosition().x < 0) return true;
    else if(snake.front().getPosition().y > (Height - velocity) || snake.front().getPosition().y < 0) return true;

   // for(int i = 1; i < snake.size(); i++)
     //   if(snake.front().getPosition().x - 25.0 == snake[i].getPosition().x  && snake.front().getPosition().y - 25.0  == snake[i].getPosition().y) return true;
    return false;
}

const bool Snake::eatFood(const sf::RectangleShape &food)
{
    if(snake.front().getPosition().x == food.getPosition().x && snake.front().getPosition().y == food.getPosition().y)
    {
        std::cout << "Eating food...\n";
        score += 1;
        snake_elongate();
        return true;
    }
    return false;
}

void Snake::snake_elongate()
{
    snake_segment.setPosition(snake[snake.size() - 1].getPosition() - vec);
    snake_segment.setFillColor(sf::Color::Magenta);
    snake.push_back(snake_segment);

}