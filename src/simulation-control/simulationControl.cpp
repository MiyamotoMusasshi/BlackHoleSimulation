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
            std::cout << "position: " << "(" << objects[i].x << ", " << objects[i].y << ")" << std::endl;
            std::cout << "velocity: " << "(" << objects[i].velocityX << ", " << objects[i].velocityY << ")" << std::endl
                      << std::endl;
        }
    }

    int processingInput(int minValue, int maxValue)

    {
        int tmpValue;

        while (true)
        {
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
        std::cout << "press '0' to return!" << std::endl;
        int expectation = -1;
        expectation = processingInput(0, 0);
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
        std::cout << "[3] Change Object" << std::endl;
        std::cout << "[4] Show Objects" << std::endl;
        std::cout << "[5] Change step simulation" << std::endl;
        std::cout << "[6] Show step simulation" << std::endl;
        std::cout << "[0] Exit" << std::endl
                  << std::endl;

        command = processingInput(0, 6);

        switch (command)
        {
        case 4:
            showObjects(objects);
            back();
        case 6:
            std::cout << "step simulation = " << tick << std::endl
                      << std::endl;
            back();
        }
    }
}
