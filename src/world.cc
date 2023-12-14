#include "core/world.h"

namespace physims
{
    void World::registerParticle(const Particle &particle)
    {
        // for now, we make copy, consider constructing the particle in place;
        m_entities.push_back(particle);
    }

    void World::step(double dt)
    {
        assert(dt > 0);

        for (int i = 0; i < m_entities.size(); i++)
        {
            m_entities[i].addForces(m_gravity);
            m_entities[i].integrate(dt);
        }
    }

    std::ostream &operator<<(std::ostream &out, const World &world)
    {
        for (int i = 0; i < world.m_entities.size(); i++)
        {
            out << "Particle " << i << " information:" << std::endl;
            out << world.m_entities[i] << std::endl;
        }

        return out;
    }
}