#include "utils.h"
#include <cmath>

unsigned int windowWidth = 1920;
unsigned int windowHeight = 1080;

accelerationsOfObjects calculationOfAccelerations(const Object &object1, const Object &object2)
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

void calculationObjectsPosition(std::vector<Object> &objects, double tick)
{
    for (auto &o : objects)
    {
        o.accelerationX = 0.0;
        o.accelerationY = 0.0;
    }

    for (size_t i = 0; i < objects.size(); i++)
    {
        for (size_t j = i + 1; j < objects.size(); j++)
        {
            accelerationsOfObjects newAccelerationsOfObjects = calculationOfAccelerations(objects[i], objects[j]);
            objects[i].accelerationX += newAccelerationsOfObjects.accelerationXFor1Object;
            objects[i].accelerationY += newAccelerationsOfObjects.accelerationYFor1Object;
            objects[j].accelerationX += newAccelerationsOfObjects.accelerationXFor2Object;
            objects[j].accelerationY += newAccelerationsOfObjects.accelerationYFor2Object;
        }
    }

    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i].velocityX += objects[i].accelerationX * tick;
        objects[i].velocityY += objects[i].accelerationY * tick;

        objects[i].x += objects[i].velocityX * tick;
        objects[i].y += objects[i].velocityY * tick;
    }
}