#include <iostream> //SFML - Simple and Fast Multimedia Library ;D
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "include/Keys.h"

#define Width 1000
#define Height 500
#define BitsPerPixel 64

bool KeyEvent(MyKeys, sf::Event);

int main()
{
    ///Initialize main objects

    //Main window initialize
    sf::RenderWindow window;
    window.create(sf::VideoMode(Width, Height, BitsPerPixel),"Nauka-SFML");
    //Mouse object
    sf::Mouse mouse;
    //Simple text example
    sf::Font font;
    font.loadFromFile("../OpenSans-Bold.ttf");
    sf::Text Welcome_text("Hello World",font,11);
    Welcome_text.setCharacterSize(32);
    Welcome_text.setPosition(window.getSize().x/2 - Welcome_text.getGlobalBounds().width/2, window.getSize().y/2 - Welcome_text.getGlobalBounds().height/2); //setting text position
    //Creating simple square ...[]
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(75.0, 75.0)); //setting rectangle size to 75x75 so its a square now :)
    square.setFillColor(sf::Color::White); //color
    square.setOrigin(static_cast<float>(75.0 / 2), static_cast<float>(75.0 / 2)); //setting origin(center) of square
    square.setPosition(Width/2, Height/4); //square should be over the text
    //event initialize
    sf::Event event{};
    //keys bindings..
        MyKeys key;
        std::map <std::string, MyKeys> Keys;
        //move left
        key.myInputType = KeyboardInput;
        key.myEventType = sf::Event::KeyPressed;
        key.myKeyCode = sf::Keyboard::A;
        Keys["move_left"] = key;
        //move right
        key.myInputType = KeyboardInput;
        key.myEventType = sf::Event::KeyPressed;
        key.myKeyCode = sf::Keyboard::D;
        Keys["move_right"] = key;
        //move up
        key.myInputType = KeyboardInput;
        key.myEventType = sf::Event::KeyPressed;
        key.myKeyCode = sf::Keyboard::W;
        Keys["move_up"] = key;
        //move down
        key.myInputType = KeyboardInput;
        key.myEventType = sf::Event::KeyPressed;
        key.myKeyCode = sf::Keyboard::S;
        Keys["move_down"] = key;

    ///End of initialize...
    //Main game loop...
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) 
            { 
                window.close();
            }

            if(KeyEvent(Keys["move_left"], event))
            {
                square.setPosition(square.getPosition().x - 5.0f, square.getPosition().y);
            }
            if(KeyEvent(Keys["move_right"], event))
            {
                square.setPosition(square.getPosition().x + 5.0f, square.getPosition().y);
            }
            if(KeyEvent(Keys["move_up"], event))
            {
                square.setPosition(square.getPosition().x, square.getPosition().y - 5.0f);
            }
            if(KeyEvent(Keys["move_down"], event))
            {
                square.setPosition(square.getPosition().x, square.getPosition().y + 5.0f);
            }
        }

        window.clear(sf::Color::Black);

        window.draw(Welcome_text);
        window.draw(square);
        window.display();
    }
    return 0;
}

bool KeyEvent(MyKeys k, sf::Event ev)
{
    //Mouse event
    if(k.myInputType == MouseInput && k.myEventType == ev.type && k.myMouseButton == ev.mouseButton.button) return true;
    //Keyboard event
    if(k.myInputType == KeyboardInput && k.myEventType == ev.type && k.myKeyCode == ev.key.code) return true;

    return false;
}
