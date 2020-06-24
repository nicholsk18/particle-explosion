//
// Created by knichols on 6/24/20.
//

#include "Screen.h"

namespace particle {

    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

    }

    bool Screen::init() {
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL init failed." << std::endl;
            return false;
        }

        m_window = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (m_window == nullptr) {
            SDL_Quit();
            std::cout << "Could not create window: " << SDL_GetError() << std::endl;
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (m_renderer == nullptr) {
            std::cout << "Could not create renderer" << std::endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        if (m_texture == nullptr) {
            std::cout << "Could not create texture" << std::endl;
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        // need to write error checking make sure it can allocate mem
        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        for(int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
            m_buffer[i] = 0xFFFF00FF;
        }
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
        return true;
    }

    bool Screen::processEvents() {
        return false;
    }

    void Screen::close() {
// free pointer
        delete[] m_buffer;

        // destroy sdl
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

}