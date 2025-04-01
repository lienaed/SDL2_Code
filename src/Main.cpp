#include <iostream>
#include <frame.hpp>

int main ()
{
    const int FPS = 60;
    const int frameDelay = 1 / FPS;
    uint32_t frameStart;

    while (game -> state())
    {
        frameStart = SDL_GetTicks();



        frameStart = SDL_GetTicks() - frameStart;
        if (frameStart < frameDelay)
            SDL_Delay (frameDelay - frameStart);
        else
            std::cout << "Low Frame" << std::endl;

    }

    return 0;
}