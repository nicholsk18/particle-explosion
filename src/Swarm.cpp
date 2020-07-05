//
// Created by knichols on 6/29/20.
//

#include "Swarm.h"
namespace pix {
    Swarm::Swarm(): lastTime(0) {
        m_pParticles = new Particle[NPARTICLES];
    }

    Swarm::~Swarm() {
        delete[] m_pParticles;
    }

    void Swarm::update(int elapsed) {
        // how much time has elapsed since last time
        int interval = elapsed - lastTime;

        for(int i = 0; i < pix::Swarm::NPARTICLES; i++) {
            m_pParticles[i].update(interval);
        }

        lastTime = elapsed;
    }
}