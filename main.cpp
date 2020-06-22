#include <iostream>
#include <SDL2/SDL.h>

int main() {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL init failed." << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        SDL_Quit();
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 2;
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

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
