//
// Created by knichols on 6/29/20.
//

#include "Swarm.h"
namespace pix {
    Swarm::Swarm() {
        m_pParticles = new Particle[NPARTICLES];
    }

    Swarm::~Swarm() {
        delete[] m_pParticles;
    }
}