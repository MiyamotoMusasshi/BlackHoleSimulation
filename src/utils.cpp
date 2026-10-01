#include "utils.h"
#include <cmath>

unsigned int windowWidth = 1920;
unsigned int windowHeight = 1080;

accelerationsOfObjects calculationOfAccelerations(Object object1, Object object2)
{

    double deltaX = object2.x - object1.x;
    double deltaY = object2.y - object1.y;
    double distance = pow(pow(deltaX, 2) + pow(deltaY, 2), 0.5);

    double force = (object1.mass * object2.mass) / (distance * distance);

    double acceleration1 = force / object1.mass;
    double acceleration2 = force / object2.mass;

    double acceleration1X = acceleration1 * (deltaX / distance);
    double acceleration1Y = acceleration1 * (deltaY / distance);

    double acceleration2X = -acceleration2 * (deltaX / distance);
    double acceleration2Y = -acceleration2 * (deltaY / distance);

    accelerationsOfObjects result = {acceleration1X, acceleration1Y, acceleration2X, acceleration2Y};

    return result;
};