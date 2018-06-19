#include <unistd.h>
#include "../include/Level.h"

Level::Level()
{
    this->x = 12.5;
    this->y = 12.5;
    square.setSize(sf::Vector2f(25.0, 25.0));
    square.setPosition(x, y);
    square.setFillColor(sf::Color::White);
    square.setOrigin(12.5, 12.5);

    food.setSize(sf::Vector2f(25.0, 25.0));
    food.setPosition(600, 200);
    food.setFillColor(sf::Color::Red);
    //food.setOrigin(12.5, 12.5);
}

Level::~Level() = default;

const sf::RectangleShape& Level::getFood() { return this->food; }

const void Level::initialize()
{
    while(square.getPosition().x < Width - velocity)
    {
        squares.push_back(square);
        square.move(velocity, 0);
    }
    while(square.getPosition().y < Height - velocity)
    {
        squares.push_back(square);
        square.move(0, velocity);
    }
    while(square.getPosition().x > velocity)
    {
        squares.push_back(square);
        square.move(-velocity, 0);
    }
    while(square.getPosition().y > velocity)
    {
        squares.push_back(square);
        square.move(0, -velocity);
    }

}

void Level::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    for(int i = 0; i < squares.size(); i++) {
        target.draw(this->squares[i], state);
    }
}

const void Level::generate_position()
{
    std::random_device rd; //generator liczb pseudolosowych...
    std::uniform_int_distribution<int> x_distribution(1, 38); //w podanym zakresie
    std::uniform_int_distribution<int> y_distribution(1, 30); //w podanym zakresie
    float x_axis = 25.0f * x_distribution(rd);
    float y_axis = 25.0f * y_distribution(rd);
    std::cout << "Food coordinates:\n";
    std::cout << "X = " << x_axis << std::endl;
    std::cout << "Y = " << y_axis << std::endl;
    food.setPosition(x_axis, y_axis);
}

const void Level::spawnFood(sf::RenderTarget &target)
{
    target.draw(food);
}
