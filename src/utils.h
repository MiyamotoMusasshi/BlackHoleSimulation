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

    double accelerationX;
    double accelerationY;
};
struct accelerationsOfObjects
{
    double accelerationXFor1Object;
    double accelerationYFor1Object;
    double accelerationXFor2Object;
    double accelerationYFor2Object;
};

accelerationsOfObjects calculationOfAccelerations(const Object &object1, const Object &object2);

void calculationObjectsPosition(std::vector<Object> &objects, double tick);
