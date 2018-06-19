#include <iostream> //SFML - Simple and Fast Multimedia Library ;D
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "include/Level.h"
#include "include/Keys.h"
#include "include/Snake.h"

#define Width 1000
#define Height 800
#define BitsPerPixel 64

bool KeyEvent(MyKeys, sf::Event);

int main()
{
    ///Initialize main objects

    //Main window initialize
    sf::RenderWindow window;
    window.create(sf::VideoMode(Width, Height, BitsPerPixel),"Nauka-SFML");
    window.setFramerateLimit(10); //setting fps rate
    //Mouse object
    sf::Mouse mouse;
    //Main text
    sf::Font font;
    font.loadFromFile("../OpenSans-Bold.ttf");
    sf::Text Welcome_text("SuperSnake",font,25);
    Welcome_text.setCharacterSize(64);
    Welcome_text.setPosition(window.getSize().x/2 - Welcome_text.getGlobalBounds().width/2, window.getSize().y/2 - Welcome_text.getGlobalBounds().height/2); //setting text position
    //event initialize
    sf::Event event{};
    //Initialize level
    Level level;
    level.initialize();
    //Initialize Snake..
    Snake snake;
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
        //spawn food...
        key.myInputType = KeyboardInput;
        key.myEventType = sf::Event::KeyPressed;
        key.myKeyCode = sf::Keyboard::F;
        Keys["spawn_food"] = key;

    //initialize score information
    sf::Text Score;
    Score.setFont(font);
    Score.setCharacterSize(32);
    Score.setFillColor(sf::Color::Green);
    Score.setPosition(Width/8, Height/8);
    ///End of initialize...

    //Main game loop...
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            if(KeyEvent(Keys["move_left"], event))
            {
                snake.move("left");
            }
            if(KeyEvent(Keys["move_right"], event))
            {
                snake.move("right");
            }
            if(KeyEvent(Keys["move_up"], event))
            {
                snake.move("up");
            }
            if(KeyEvent(Keys["move_down"], event))
            {
                snake.move("down");
            }
            if(KeyEvent(Keys["spawn_food"], event))
            {
                level.generate_position();
            }
        }
        window.clear(sf::Color::Black);
        //Draw section
        window.draw(Welcome_text);
        window.draw(Score);
        window.draw(snake);
        window.draw(level);
        level.spawnFood(window);
        //Lets make running snake :D
        snake.run();
        //Checking for collisions with walls and food :P
        if(snake.eatFood(level.getFood())) level.generate_position();
        //Updating score points...
        Score.setString("Your score is " + std::to_string(snake.getScore()));
        if(snake.check_Collisions())
        {
            std::cout << "You losed!" << std::endl;
            break;
        }
        //
        window.display();
    }
    return 0;
}

bool KeyEvent(MyKeys k, sf::Event ev)
{
    //Mouse event
    if(k.myInputType == MouseInput && k.myEventType == ev.type && k.myMouseButton == ev.mouseButton.button) return true;
    //Keyboard event
    else if(k.myInputType == KeyboardInput && k.myEventType == ev.type && k.myKeyCode == ev.key.code) return true;
    return false;
}
