#include <unistd.h>
#include "../include/Level.h"

Level::Level()
{
    this->x = 20;
    this->y = 20;
    square.setSize(sf::Vector2f(25.0, 25.0));
    square.setPosition(x, y);
    square.setFillColor(sf::Color::White);
    square.setOrigin(12.5, 12.5);
}

Level::~Level() = default;

const void Level::initialize()
{
    while(square.getPosition().x < Width - 25)
    {
        squares.push_back(square);
        square.move(30.0, 0);
    }
    while(square.getPosition().y < Height - 25)
    {
        squares.push_back(square);
        square.move(0, 30.0);
    }
    while(square.getPosition().x > 25)
    {
        squares.push_back(square);
        square.move(-30.0, 0);
    }
    while(square.getPosition().y > 25)
    {
        squares.push_back(square);
        square.move(0, -30.0);
    }

}

void Level::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    for(int i = 0; i < squares.size(); i++) {
        target.draw(this->squares[i], state);
    }
}