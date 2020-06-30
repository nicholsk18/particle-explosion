//
// Created by knichols on 6/24/20.
//

#include "Screen.h"

namespace pix {

    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

    }

    bool Screen::init() {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }

        m_window = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (m_window == nullptr) {
            SDL_Quit();
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (m_renderer == nullptr) {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        if (m_texture == nullptr) {
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        // need to write error checking make sure it can allocate mem
        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        return true;
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

        // Only plot a pix if its within screen width or height
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }
        Uint32 color = 0;

        // add a color and shift it right
        // realign elements to be proper format
        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        m_buffer[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::update() {
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }

    bool Screen::processEvents() {
        SDL_Event event;

        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) {
                return false;
            }
        }
        return true;
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