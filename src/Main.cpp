#include "frame.hpp"
#undef main

Frame* game = nullptr;

int main ()
{
    //Frame setting
    const int FPS = 60;
    const int FrameDelay = 1000 / FPS;
    uint32_t FrameStart;

    //Initialize game
    game = new Frame();
    game -> init("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);

    //Main loop
    while (game -> state())
    {
        FrameStart = SDL_GetTicks();

        game -> event();
        game -> update();
        game -> render(); 

        //Frame restriction
        FrameStart = SDL_GetTicks() - FrameStart;
        if (FrameStart < FrameDelay)
            SDL_Delay (FrameDelay - FrameStart);
        else
            std::cout << "Low Frame" << std::endl;
    }
    
    game -> clear();
    return 0;
}