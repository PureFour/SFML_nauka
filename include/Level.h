
#ifndef SFML_NAUKA_LEVEL_H
#define SFML_NAUKA_LEVEL_H

#define Width 1000
#define Height 800
#include <SFML/Graphics.hpp>

class Level :public sf::Drawable
{
private:
    float x;
    float y;
    sf::RectangleShape square;
    std::vector<sf::RectangleShape> squares;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
public:
    Level();
    ~Level();
    const void initialize();
};


#endif //SFML_NAUKA_LEVEL_H
