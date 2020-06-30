//
// Created by knichols on 6/29/20.
//

#ifndef PARTICLE_EXPLOSION_PARTICLE_H
#define PARTICLE_EXPLOSION_PARTICLE_H

namespace pix {
    struct Particle {
        // set public
        // because there going to be many particles
        double m_x;
        double m_y;

        double m_xSpeed;
        double m_ySpeed;

    public:
        Particle();
        virtual ~Particle();
        void update();
    };
}


#endif //PARTICLE_EXPLOSION_PARTICLE_H
