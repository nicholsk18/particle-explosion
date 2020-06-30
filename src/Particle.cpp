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
    }

    Particle::~Particle() {}
}
