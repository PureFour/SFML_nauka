
#ifndef SFML_NAUKA_SNAKE_H
#define SFML_NAUKA_SNAKE_H

#define Width 1000
#define Height 800
#include <SFML/Graphics.hpp>

class Snake : public sf::Drawable
{
private:
    //snake shape
    sf::RectangleShape snake;
    unsigned int score;
protected:
    //position
    const float x;
    const float y;
    //size
    const float size_x = 25.0;
    const float size_y = 25.0;
    //velocity
    const float velocity = 25.0;
    //directory
    sf::Vector2f vec;
    //override Drawable draw method...
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void snake_elongate();
public:
    Snake(float _x = 25, float _y = 25);
    ~Snake();
    void run();
    const bool eatFood(const sf::RectangleShape &);
    const bool check_Collisions();
    const void move(const std::string&);
    //get functions
    unsigned int &getScore();

    
};


#endif //SFML_NAUKA_SNAKE_H
