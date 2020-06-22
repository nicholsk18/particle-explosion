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

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (renderer == nullptr) {
        std::cout << "Could not create renderer" << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    if (texture == nullptr) {
        std::cout << "Could not create texture" << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    // need to write error checking make sure it can allocate mem
    Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
//
//    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
//    SDL_RenderClear(renderer);
//    SDL_RenderCopy(renderer, texture, NULL, NULL);
//    SDL_RenderPresent(renderer);

    // window open?
    bool isRunning = false;

    SDL_Event event;

    while (!isRunning) {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) {
                isRunning = true;
            }
        }

        SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    // free pointer
    delete[] buffer;

    // destroy sdl
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
