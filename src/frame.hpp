#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class frame
{
    public:
        frame();
        ~frame();
        void init(const char* title, int x, int y, int w, int h, bool fullscreen);
        void update();
        void draw();
        bool state();
        void event();
        void clean();


    private:
        bool running;
        SDL_Window* window;
}