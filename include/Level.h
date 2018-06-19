
#ifndef SFML_NAUKA_LEVEL_H
#define SFML_NAUKA_LEVEL_H

#define Width 1000
#define Height 800
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

class Level :public sf::Drawable
{
private:
    float x;
    float y;
    const float velocity = 25.0;
    sf::RectangleShape square;
    sf::RectangleShape food;
    std::vector<sf::RectangleShape> squares;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
public:
    Level();
    ~Level();
    const void initialize();
    const void generate_position();
    const void spawnFood(sf::RenderTarget &);
};


#endif //SFML_NAUKA_LEVEL_H
