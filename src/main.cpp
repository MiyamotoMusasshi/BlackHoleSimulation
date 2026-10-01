#include <iostream>
#include "utils.h"
#include <SFML/Graphics.hpp>

Object blackHole = {10000.0, 50.0, (double)windowWidth / 2, (double)windowHeight / 2, 0.0, 0.0, 0.0, 0.0};
Object planet1 = {1.0, 10.0, (double)windowWidth / 2 + 50.0, (double)windowHeight / 2 - 50.0, 10.0, 10.0, 0.0, 0.0};
double dt = 0.1;

int main()
{

    sf::RenderWindow window(
        sf::VideoMode({windowWidth, windowHeight}),
        "Black Hole");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        accelerationsOfObjects newAccelerationsOfObjects = calculationOfAccelerations(blackHole, planet1);
        planet1.accelerationX = newAccelerationsOfObjects.accelerationXFor2Object;
        planet1.accelerationY = newAccelerationsOfObjects.accelerationYFor2Object;
        blackHole.accelerationX = newAccelerationsOfObjects.accelerationXFor1Object;
        blackHole.accelerationY = newAccelerationsOfObjects.accelerationYFor1Object;

        planet1.velocityX += planet1.accelerationX * dt;
        planet1.velocityY += planet1.accelerationY * dt;

        planet1.x += planet1.velocityX * dt;
        planet1.y += planet1.velocityY * dt;

        blackHole.velocityX += blackHole.accelerationX * dt;
        blackHole.velocityY += blackHole.accelerationY * dt;

        blackHole.x += blackHole.velocityX * dt;
        blackHole.y += blackHole.velocityY * dt;

        sf::CircleShape planet1Render((float)planet1.size);
        planet1Render.setFillColor(sf::Color::Green);
        planet1Render.setPosition({sf::Vector2<float>(planet1.x, planet1.y)});

        sf::CircleShape blackHoleRender((float)blackHole.size);
        blackHoleRender.setFillColor(sf::Color::Black);
        blackHoleRender.setPosition({sf::Vector2<float>(blackHole.x, blackHole.y)});

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::White);

        window.draw(planet1Render);
        window.draw(blackHoleRender);

        window.display();
    }

    return 0;
}