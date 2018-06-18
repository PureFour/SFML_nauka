
#ifndef SFML_NAUKA_SNAKE_H
#define SFML_NAUKA_SNAKE_H

#include <SFML/Graphics.hpp>

class Snake : public sf::Drawable
{
private:
    //snake shape
    sf::RectangleShape snake;
    //position
    const float x;
    const float y;
    //size
    const float size_x = 25.0;
    const float size_y = 25.0;
    //velocity
    const sf::Vector2f velocity;
    //override Drawable draw method...
    void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
public:
    Snake(float _x = 500, float _y = 250);
    ~Snake();
    
};


#endif //SFML_NAUKA_SNAKE_H
