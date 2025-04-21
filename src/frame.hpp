#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <json.hpp>

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
};