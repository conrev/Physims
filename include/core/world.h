#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <iostream>
#include <Eigen/Dense>
#include "core/particle.h"

namespace physims
{

    class World
    {
    public:
        World()
        {
            m_worldName = "Physims World";
            m_gravity = Eigen::Vector3d{0.0, -9.81, 0.0};
        }
        // consider not copying
        World(Eigen::Vector3d gravity) : m_gravity(gravity) {}
        void step(double dt);
        void registerParticle(const Particle &particle);

    private:
        std::string m_worldName;
        Eigen::Vector3d m_gravity;
        std::vector<Particle>
            m_entities;

    public:
        friend std::ostream &operator<<(std::ostream &out, const World &world);
    };

}

#endif