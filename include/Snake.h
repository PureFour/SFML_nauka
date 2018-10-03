
#ifndef SFML_NAUKA_SNAKE_H
#define SFML_NAUKA_SNAKE_H

#define Width 1000
#define Height 800
#include <SFML/Graphics.hpp>

class Snake : public sf::Drawable
{
private:
    //snake struct
    struct snake
    {
        //snake_segment shape
        sf::RectangleShape snake_segment;
        //velocity vector
        sf::Vector2f vec;
    };
    std::vector<struct snake> wonsz;
    unsigned int score;
    //position
    const float x;
    const float y;
    //size
    const float size_x = 25.0;
    const float size_y = 25.0;
    //velocity
    const float velocity = 25.0;
    //override Drawable draw method...
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void snake_elongate();
public:
    Snake(float _x = 250, float _y = 250);
    ~Snake();
    void run();
    const bool eatFood(const sf::RectangleShape &);
    const bool check_Collisions();
    const void move(const std::string&);
    //get functions
    unsigned int &getScore();

    
};


#endif //SFML_NAUKA_SNAKE_H
