#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

int main() {

    particle::Screen screen;

    if(screen.init() == false) {
        std::cout << "Error initialising sdl" << std::endl;
    }

    // window open?
    bool isRunning = false;

    SDL_Event event;

    while (!isRunning) {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) {
                isRunning = true;
            }
        }
    }

    screen.close();

    return 0;
}
