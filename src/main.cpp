#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

int main() {

    particle::Screen screen;

    if(screen.init() == false) {
        std::cout << "Error initialising sdl" << std::endl;
    }

    while (true) {

        // draw particles
        for(int x = 0; x < particle::Screen::SCREEN_HEIGHT; x++) {
            for(int y = 0; y < particle::Screen::SCREEN_WIDTH; y++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }

        screen.setPixel(400, 300, 255, 255, 255);

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
