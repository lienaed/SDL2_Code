#include "frame.hpp"

SDL_Renderer* renderer;

frame::frame(){}
frame::~frame(){}

void frame::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
    //Fullscreen detect
    int flag == 0;
    if (fullscreen)
        flag = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init (SDL_INIT_EVERYTHING) == 0)
    {
        //Create window
        std::cout << "Subsystem Initialized." << std::endl;
        window = SDL_CreateWindow (title, x, y, w, h, flag);
        if (window)
            std::cout << "Window created." << std::endl;
        else
            std::cout << "Window creating failed." << std::endl;
        
        //Create renderer
        renderer = SDL_CreateRenderer (window, -1, 0);
        if (renderer)
                std::cout << "Renderer created." << std::endl;
        else
                std::cout << "Renderer creating failed." << std::endl;
        running = 1;
        //Other initialization

    }
    else
        running = 0;
}

void frame::update()
{

}

void frame::draw()
{
    SDL_RenderClear (renderer);
    SDL_RenderPresent (renderer);
}

bool frame::state()
{
    return running;
}