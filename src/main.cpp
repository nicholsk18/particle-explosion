#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include "Screen.h"
#include "Swarm.h"

int main() {

    // seeds random number
    // dont return anything
    srand(time(NULL));

    pix::Screen screen;

    if(screen.init()) {
        std::cout << "Error initialising sdl" << std::endl;
    }

    pix::Swarm swarm;

    while (true) {
        int elapsed = SDL_GetTicks();

        screen.clear();
        swarm.update(elapsed);

        // unsigned so its always positive
        // mult elapsed by dif number to change speed
        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0001)) * 128;

        const pix::Particle* const pParticles = swarm.getParticles();
        for(int i = 0; i < pix::Swarm::NPARTICLES; i++) {
            pix::Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * pix::Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * pix::Screen::SCREEN_WIDTH / 2 + pix::Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(x, y, red, green, blue);
        }

        // draw the screen
        screen.update();

        // check for messages/events
        if(!screen.processEvents()){
            break;
        }
    }

    screen.close();

    return 0;
}
