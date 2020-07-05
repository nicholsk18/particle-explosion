//
// Created by knichols on 6/29/20.
//

#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace pix {
    Particle::Particle(): m_x(0), m_y(0) {

        // create angle
        m_direction = (2 * M_PI * rand()) / RAND_MAX;
        // create speed
        m_speed = (0.0001 * rand()) / RAND_MAX;
    }

    Particle::~Particle() {}

    void Particle::update(int interval) {
        double xSpeed = m_speed * cos(m_direction);
        double ySpeed = m_speed * sin(m_direction);

        m_x += xSpeed * interval;
        m_y += ySpeed * interval;
    }
}
