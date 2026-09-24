#include <iostream>
#include "utils.h"

int main()
{
    Object blackHole = {1000000000000000.0, 0.0, 0.0, 0.0, 0.0};
    Object randomPlanet = {1.0, 50.0, 50.0, 10.0, 5.0};

    double dt = 1.0;
    for (int step = 0; step < 100; step++)
    {

        double dx = blackHole.x - randomPlanet.x;
        double dy = blackHole.y - randomPlanet.y;

        double distance = std::sqrt(dx * dx + dy * dy);

        double directionX = dx / distance;
        double directionY = dy / distance;

        double acceleration = (G * blackHole.mass) / (distance * distance);

        double accelerationX = directionX * acceleration;
        double accelerationY = directionY * acceleration;

        randomPlanet.velocityX = randomPlanet.velocityX + accelerationX * dt;
        randomPlanet.velocityY = randomPlanet.velocityY + accelerationY * dt;

        randomPlanet.x = randomPlanet.x + randomPlanet.velocityX * dt;
        randomPlanet.y = randomPlanet.y + randomPlanet.velocityY * dt;

        std::cout << "SIMULATION TIME " << step << std::endl;
        std::cout << "Planet coordinates: (" << randomPlanet.x << ", " << randomPlanet.y << ")" << std::endl;
        std::cout << "Planet's speed: (" << randomPlanet.velocityX << ", " << randomPlanet.velocityY << ")" << std::endl;
    }

    return 0;
}