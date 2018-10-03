#include <iostream>
#include "../include/Snake.h"

Snake::Snake(float _x, float _y) : x(_x), y(_y)
{
    //segment initialize
    snake head = snake();
    head.snake_segment.setSize(sf::Vector2f(size_x, size_y));
    head.snake_segment.setPosition(x, y);
    head.snake_segment.setFillColor(sf::Color::Cyan);
    head.vec = sf::Vector2f(25.0, 0);
    wonsz.push_back(head);
    this->score = 0;
}

Snake::~Snake() = default;

void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    for(auto &i : wonsz)
        target.draw(i.snake_segment, state);
}

unsigned int& Snake::getScore() { return this->score; }

void Snake::run()
{
    wonsz.front().snake_segment.move(wonsz.front().vec);
    for(auto i = wonsz.begin() + 1; i < wonsz.end(); i++)
        i->snake_segment.setPosition((i - 1)->snake_segment.getPosition() - (i - 1)->vec);
}

const void Snake::move(const std::string &direction)
{
    if(direction == "left" && wonsz.front().vec.x != velocity)
    {
        this->wonsz.front().vec.x = -velocity;
        this->wonsz.front().vec.y = 0;
        return;
    }
    if(direction == "right" && wonsz.front().vec.x == 0)
    {
        this->wonsz.front().vec.x = velocity;
        this->wonsz.front().vec.y = 0;
        return;
    }
    if(direction == "down" && wonsz.front().vec.y == 0)
    {
        this->wonsz.front().vec.x = 0;
        this->wonsz.front().vec.y = velocity;
        return;
    }
    if(direction == "up" && wonsz.front().vec.y != velocity)
    {
        this->wonsz.front().vec.x = 0;
        this->wonsz.front().vec.y = -velocity;
        return;
    }
}

const bool Snake::check_Collisions()
{
    if(wonsz.front().snake_segment.getPosition().x > (Width - velocity) || wonsz.front().snake_segment.getPosition().x < 0) return true;
    else if(wonsz.front().snake_segment.getPosition().y > (Height - velocity) || wonsz.front().snake_segment.getPosition().y < 0) return true;

    //for(int i = 1; i < wonsz.size(); i++)
    //if(wonsz.front().snake_segment.getPosition().x == wonsz[i].snake_segment.getPosition().x  && wonsz.front().snake_segment.getPosition().y == wonsz[i].snake_segment.getPosition().y) return true;
    return false;
}

const bool Snake::eatFood(const sf::RectangleShape &food)
{
    if(wonsz.front().snake_segment.getPosition().x == food.getPosition().x && wonsz.front().snake_segment.getPosition().y == food.getPosition().y)
    {
        std::cout << "Eating food...\n";
        score += 1;
        snake_elongate();
        return true;
    }
    return false;
}

void Snake::snake_elongate() //????
{
    snake another = snake();
    wonsz.push_back(another);
    wonsz.back().snake_segment.setPosition(wonsz[wonsz.size()].snake_segment.getPosition() - wonsz[wonsz.size() -1 ].vec);
    wonsz.back().snake_segment.setSize(sf::Vector2f(size_x, size_y ));
    wonsz.back().snake_segment.setFillColor(sf::Color::Green);
    //wonsz.back().vec = wonsz[wonsz.size() - 1].vec;

}