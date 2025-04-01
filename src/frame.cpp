#include "Frame.hpp"

SDL_Renderer* Frame::renderer = nullptr;
Frame::Frame(){}
Frame::~Frame(){}

void Frame::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
    //Fullscreen detect
    int flag = 0;
    if (fullscreen)
        flag = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init (SDL_INIT_EVERYTHING) == 0)
    {
        //Create window
        std::cout << "Subsystem initialized." << std::endl;
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
    {
        std::cout << "Subsystem initializing failed." << std::endl;
        running = 0;
    }

}

//Event
void Frame::event()
{
    SDL_Event event;
    SDL_PollEvent (&event);
    switch (event.type)
    {
        case SDL_QUIT:
            running = 0;
            break;

        default:
            break;
    }
}

//Update
void Frame::update()
{
    SDL_SetRenderDrawColor (renderer, 63, 83, 143, 255);
}

//Render
void Frame::render()
{
    SDL_RenderClear (renderer);
    SDL_RenderPresent (renderer);
}

//State
bool Frame::state()
{
    return running;
}