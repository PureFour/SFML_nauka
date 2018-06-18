
#ifndef SFML_NAUKA_KEYS_H
#define SFML_NAUKA_KEYS_H

#include <SFML/Window.hpp>

enum InputType
{
    KeyboardInput,
    MouseInput,
    JoystickInput
};

struct MyKeys
{
    InputType myInputType;
    sf::Event::EventType myEventType;
    sf::Keyboard::Key myKeyCode;
    sf::Mouse::Button myMouseButton;
};

#endif //SFML_NAUKA_KEYS_H
