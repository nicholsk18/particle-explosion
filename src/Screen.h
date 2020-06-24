//
// Created by knichols on 6/24/20.
//

#ifndef PARTICLE_EXPLOSION_SCREEN_H
#define PARTICLE_EXPLOSION_SCREEN_H

#include <iostream>
#include <SDL2/SDL.h>

namespace particle {

    class Screen {
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;

    public:
        Screen();
        bool init();
        bool processEvents();
        void close();

    };

}


#endif //PARTICLE_EXPLOSION_SCREEN_H
