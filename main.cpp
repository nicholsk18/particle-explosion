#include <iostream>
#include <SDL2/SDL.h>

int main() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL init failed." << std::endl;
        return 1;
    }

    std::cout << "SDL Init succeeded." << std::endl;

    SDL_Quit();

    return 0;
}
