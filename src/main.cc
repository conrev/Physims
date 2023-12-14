// #include <iostream>
#include <Eigen/Dense>
#include "core/particle.h"
#include "core/world.h"

int main()
{
    physims::World testWorld{};
    physims::Particle oneParticle(
        Eigen::Vector3d{-8, 57.0, 0});

    testWorld.registerParticle(oneParticle);
    float dt = 1;
    float TIME_TO_SIM = 10;
    float currentTime = 0;
    std::cout << testWorld;

    while (currentTime < TIME_TO_SIM)
    {
        testWorld.step(dt);
        std::cout << testWorld;
        currentTime += dt;
    }
}