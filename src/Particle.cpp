//
// Created by knichols on 6/29/20.
//

#include "Particle.h"
#include <stdlib.h>

namespace pix {
    Particle::Particle() {
        // returns number between -1, 1
        m_x = (2.0 * rand() / RAND_MAX) - 1;
        m_y = (2.0 * rand() / RAND_MAX) - 1;

        m_xSpeed = 0.005 * ((2.0 * rand()/RAND_MAX) - 1);
        m_ySpeed = 0.005 * ((2.0 * rand()/RAND_MAX) - 1);
    }

    Particle::~Particle() {}

    void Particle::update() {
        m_x += m_xSpeed;
        m_y += m_ySpeed;

        // make particles bounce of edge of screen
        if(m_x < -1 || m_x >= 1.0) {
            m_xSpeed = -m_xSpeed;
        }
        if(m_y < -1 || m_y >= 1.0) {
            m_ySpeed = -m_ySpeed;
        }
    }
}
