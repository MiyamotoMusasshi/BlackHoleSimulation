#include "../utils/utils.h"
#include <vector>
#include "simulationControl.h"
#include <iostream>

namespace
{
    void showObjects(const std::vector<Object> &objects)
    {
        std::cout << "Objects: " << std::endl
                  << std::endl;

        for (size_t i = 0; i < objects.size(); i++)
        {
            std::cout << "[" << i << "] " << objects[i].name << std::endl;
            std::cout << "mass = " << objects[i].mass << "; size = " << objects[i].size << std::endl;
            std::cout << "position: " << "(" << objects[i].x - windowWidth / 2 << ", " << objects[i].y - windowHeight / 2 << ")" << std::endl;
            std::cout << "velocity: " << "(" << objects[i].velocityX << ", " << objects[i].velocityY << ")" << std::endl
                      << std::endl;
        }
    }

    int processingInput(int minValue, int maxValue, std::string whatIsEnter = "")
    {
        int tmpValue;

        while (true)
        {
            std::cout << whatIsEnter << std::endl;

            if (std::cin >> tmpValue && tmpValue >= minValue && tmpValue <= maxValue)
            {
                break;
            }

            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        return tmpValue;
    }
    double processingInput(double minValue, double maxValue, std::string whatIsEnter = "")
    {
        double tmpValue;

        while (true)
        {
            std::cout << whatIsEnter << std::endl;

            if (std::cin >> tmpValue && tmpValue >= minValue && tmpValue <= maxValue)
            {
                break;
            }

            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        return tmpValue;
    }

    void back()
    {
        std::cout << "[0] to return!" << std::endl;
        processingInput(0, 0);
    }
}

void simulationControl(std::vector<Object> &objects, double &tick)
{
    int command = -1;

    std::cout << "=======================================================================================" << std::endl;
    std::cout << "                   Welcome to a simple simulation!" << std::endl;
    std::cout << "         Press 'Space' to return to the console after launching." << std::endl;
    std::cout << "=======================================================================================" << std::endl;

    while (command != 0)
    {
        std::cout << "[1] Add Object" << std::endl;
        std::cout << "[2] Remove Object" << std::endl;
        std::cout << "[3] Show Objects" << std::endl;
        std::cout << "[4] Change step simulation" << std::endl;
        std::cout << "[5] Show step simulation" << std::endl;
        std::cout << "[0] Exit" << std::endl
                  << std::endl;

        command = processingInput(0, 6);

        switch (command)
        {
        case 3:
            showObjects(objects);
            back();
            break;
        case 5:
            std::cout << "step simulation = " << tick << std::endl
                      << std::endl;
            back();
            break;
        case 2:
        {
            showObjects(objects);
            int deletedIndex = processingInput(-1, objects.size() - 1, "Specify the number of the object to delete or [-1] to return: ");

            if (deletedIndex != -1)
                objects.erase(objects.begin() + deletedIndex);
            break;
        }
        case 4:
        {
            double newValueTick = processingInput(0.0, 100000.0, "Enter a new value step simulation or [0] to return:");

            if (newValueTick != 0)
                tick = newValueTick;
            break;
        }
        case 1:
        {
            std::string name;
            bool isBlackHole;
            double mass;
            double size;
            double x;
            double y;
            double velocityX;
            double velocityY;

            std::cout << "Enter the object name" << std::endl;
            std::cin >> name;

            isBlackHole = (bool)processingInput(0, 1, "Is your object a black hole? [1] Yes [0] No");
            mass = processingInput(1.0, 100000000.0, "Enter the mass");
            size = processingInput(1.0, 200.0, "Enter the size(max 200)");
            x = processingInput((double)windowWidth / (double)-2, windowWidth / (double)2, "Enter the x-coordinate");
            y = processingInput((double)windowHeight / (double)-2, windowHeight / (double)2, "Enter the y-coordinate");
            velocityX = processingInput(-100000.0, 100000.0, "Enter the x-velocity");
            velocityY = processingInput(-100000.0, 100000.0, "Enter the y-velocity");

            Object newObject = {name, isBlackHole, sf::Color::Black, mass, size, windowWidth / 2 + x, windowHeight / 2 - y, velocityX, velocityY, 0.0, 0.0};
            objects.push_back(newObject);
            break;
        }
        }
    }
}
