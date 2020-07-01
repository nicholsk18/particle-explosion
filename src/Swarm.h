//
// Created by knichols on 6/29/20.
//

#ifndef PARTICLE_EXPLOSION_SWARM_H
#define PARTICLE_EXPLOSION_SWARM_H

#include "Particle.h"

namespace pix {
    class Swarm {
    public:
        const static int NPARTICLES = 5000;

    private:
        Particle * m_pParticles;

    public:
        Swarm();
        virtual ~Swarm();
        void update();

        const Particle* const getParticles() { return m_pParticles; };
    };
}


#endif //PARTICLE_EXPLOSION_SWARM_H
