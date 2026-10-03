#include <iostream>
#include "utils.h"
#include <SFML/Graphics.hpp>
#include "vector"
#include <random>

double dt = 0.1;
std::vector<Object> objects = {{"BlackHole", 1, sf::Color::Black, 10000.0, 50.0, (double)windowWidth / 2, (double)windowHeight / 2, 0.0, 0.0, 0.0, 0.0}, {"RandomPlanet", 0, sf::Color::Black, 1.0, 10.0, (double)windowWidth / 2 + 50.0, (double)windowHeight / 2 - 50.0, 10.0, 10.0, 0.0, 0.0}};

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 255);

    for (size_t i = 0; i < objects.size(); i++)
    {
        sf::Color randomColor(distrib(gen), distrib(gen), distrib(gen));
        objects[i].color = randomColor;
    }

    sf::RenderWindow window(
        sf::VideoMode({windowWidth, windowHeight}),
        "Black Hole");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {

        calculationObjectsPosition(objects, dt);

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        for (size_t i = 0; i < objects.size(); i++)
        {
            sf::CircleShape objectRender((float)objects[i].size);
            objectRender.setFillColor(objects[i].color);
            // objectRender.setOrigin({{sf::Vector2<float>(objects[i].x, objects[i].y)}});
            objectRender.setPosition({sf::Vector2<float>(objects[i].x, objects[i].y)});
            if (objects[i].isBlackHole == 1)
            {
                objectRender.setFillColor(sf::Color::Black);
                objectRender.setOutlineThickness(5.f);
                objectRender.setOutlineColor(sf::Color::White);
            }
            window.draw(objectRender);
        }
        window.display();
    }

    return 0;
}