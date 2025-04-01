#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Frame.hpp"

Frame* game = nullptr;

int main ()
{
    const int FPS = 60;
    const int FrameDelay = 1 / FPS;
    uint32_t FrameStart;

    game = new Frame();
    game -> init("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);

    while (game -> state())
    {
        FrameStart = SDL_GetTicks();

        game -> event();
        game -> update();
        game -> render(); 

        FrameStart = SDL_GetTicks() - FrameStart;
        if (FrameStart < FrameDelay)
            SDL_Delay (FrameDelay - FrameStart);
        //else
            //std::cout << "Low Frame" << std::endl;
    }

    return 0;
}