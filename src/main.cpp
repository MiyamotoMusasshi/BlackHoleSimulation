#include <iostream>
#include "utils/utils.h"
#include <SFML/Graphics.hpp>
#include "vector"
#include <random>
#include "simulation-control/simulationControl.h"

double dt = 0.05;
Object object1 = {"Black", 1, sf::Color::Black, 1000000, 100, windowWidth / (double)2, windowHeight / (double)2, 0, 0};
Object object2 = {"planet", 0, sf::Color::Black, 10, 10, windowWidth / (double)2 + 700, windowHeight / (double)2 + 200, 10, 10};
std::vector<Object> objects = {object1, object2};

void randomizeColors()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 255);

    for (size_t i = 0; i < objects.size(); i++)
    {
        sf::Color randomColor(distrib(gen), distrib(gen), distrib(gen));
        objects[i].color = randomColor;
    }
}

int main()
{
    simulationControl(objects, dt);
    randomizeColors();

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

            if (event->is<sf::Event::KeyPressed>())
            {
                auto key = event->getIf<sf::Event::KeyPressed>()->code;

                if (key == sf::Keyboard::Key::Space)
                {
                    simulationControl(objects, dt);
                    randomizeColors();
                }
            }
        }
        window.clear();

        for (size_t i = 0; i < objects.size(); i++)
        {
            if (objects[i].isAlive != 0)
            {
                sf::CircleShape objectRender((float)objects[i].size);
                objectRender.setFillColor(objects[i].color);
                objectRender.setPosition({sf::Vector2<float>(objects[i].x, objects[i].y)});
                if (objects[i].isBlackHole == 1)
                {
                    objectRender.setFillColor(sf::Color::Black);
                    objectRender.setOutlineThickness(5.f);
                    objectRender.setOutlineColor(sf::Color::White);
                }
                window.draw(objectRender);
            }
        }
        window.display();
    }

    return 0;
}