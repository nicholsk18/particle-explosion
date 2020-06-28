#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.h"

int main() {

    particle::Screen screen;

    if(screen.init()) {
        std::cout << "Error initialising sdl" << std::endl;
    }

    while (true) {
        int elapsed = SDL_GetTicks();

        // unsigned so its always positive
        // mult elapsed by dif number to change speed
        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

        // draw particles
        for(int y = 0; y < particle::Screen::SCREEN_HEIGHT; y++) {
            for(int x = 0; x < particle::Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
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
