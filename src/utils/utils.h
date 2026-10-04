#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

extern unsigned int windowWidth;
extern unsigned int windowHeight;

struct Object
{
    std::string name;
    bool isBlackHole;
    sf::Color color;

    double mass;
    double size;

    double x;
    double y;

    double velocityX;
    double velocityY;

    double accelerationX = 0;
    double accelerationY = 0;
    bool isAlive = 1;
};

struct accelerationsOfObjects
{
    double accelerationXFor1Object;
    double accelerationYFor1Object;
    double accelerationXFor2Object;
    double accelerationYFor2Object;
};

accelerationsOfObjects calculationOfAccelerations(Object &object1, Object &object2);

void calculationObjectsPosition(std::vector<Object> &objects, double tick);
