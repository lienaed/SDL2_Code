#pragma once
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Frame
{
    public:
        Frame();
        ~Frame();
        void init(const char* title, int x, int y, int w, int h, bool fullscreen);
        void update();
        void render();
        bool state();
        void event();
        void clear();

        static SDL_Renderer* renderer;
        static int winW, winH;

    private:
        bool running = 1;
        SDL_Window *window;
        
        SDL_Rect src, dest;
};