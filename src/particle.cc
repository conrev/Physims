#include <iomanip>
#include "core/particle.h"

namespace physims
{
    void Particle::integrate(double dt)
    {
        assert(dt > 0);

        m_acceleration = m_accumForces; // * m_inverseMass;
        m_velocity += m_acceleration;
        m_position += m_velocity;

        // reset forces at the end of every step
        Particle::resetForces();
    }

    void Particle::resetForces()
    {
        m_accumForces = Eigen::Vector3d::Zero();
    }

    void Particle::addForces(const Eigen::Vector3d &force)
    {
        m_accumForces += force;
    }

    std::ostream &operator<<(std::ostream &out, const Particle &particle)
    {
        out << std::setprecision(6) << "Position: " << std::endl
            << "{ "
            << particle.m_position.x() << ", "
            << particle.m_position.y() << ", "
            << particle.m_position.z()
            << " }" << std::endl;

        // out << "Velocity: " << particle.m_velocity << std::endl;

        return out;
    }
}