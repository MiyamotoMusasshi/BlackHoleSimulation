#include <iostream>
#include "utils.h"
#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow window(
        sf::VideoMode({1920, 1080}),
        "Black Hole");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::White);

        window.display();
    }

    return 0;
}