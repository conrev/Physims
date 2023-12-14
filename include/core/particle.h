#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <Eigen/Dense>

namespace physims
{
    class Particle
    {
    public:
        Particle(const Eigen::Vector3d &position) : m_position(position),
                                                    m_velocity(Eigen::Vector3d::Zero()),
                                                    m_acceleration(Eigen::Vector3d::Zero()),
                                                    m_inverseMass(1.0) {}

        Particle(const Eigen::Vector3d &position, const Eigen::Vector3d &velocity,
                 const Eigen::Vector3d &acceleration, float inverseMass) : m_position(position),
                                                                           m_velocity(velocity),
                                                                           m_acceleration(acceleration),
                                                                           m_inverseMass(inverseMass) {}
        void addForces(const Eigen::Vector3d &force);
        void integrate(double dt);
        void resetForces();

    private:
        Eigen::Vector3d m_position;
        Eigen::Vector3d m_velocity;
        Eigen::Vector3d m_acceleration;
        Eigen::Vector3d m_accumForces;
        double m_drag = 0.995;
        double m_inverseMass;

    public:
        friend std::ostream &operator<<(std::ostream &out, const Particle &particle);
    };
}

#endif
