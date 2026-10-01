#pragma once
#include <cmath>

extern unsigned int windowWidth;
extern unsigned int windowHeight;

struct Object
{
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

accelerationsOfObjects calculationOfAccelerations(Object object1, Object object2);
