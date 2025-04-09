#include "Frame.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"
#include "OOP/GameObject.hpp"
#include "OOP/Player.hpp"
#include "OOP/Enimy.hpp"

SDL_Renderer* Frame::renderer = nullptr;
Map* level1 = new Map();

std::vector <GameObject*> gameObjects;
Player* Knight = nullptr;
Enimy* Shell = nullptr;

int Frame::winW = 0, Frame::winH = 0;

Frame::Frame(){}
Frame::~Frame(){}

//Initialization
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

        SDL_GetWindowSize (window, &winW, &winH);

        //Other initialization
        level1 -> init ("assets/Maps/Level1.json");
        Knight = new Player ("assets/Knight.png", 0, winH, 64, 64);
        gameObjects.emplace_back (Knight);
        Shell = new Enimy ("assets/Shell.png", 300, winH, 64, 64);
        gameObjects.emplace_back (Shell);

        //Clear event
        SDL_Event dump;
        while (SDL_PollEvent (&dump)){}
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
    InputManager::update();
    
    running = InputManager::keyDown (SDL_SCANCODE_ESCAPE) ? 0 : 1;

    SDL_Event event;
    while (SDL_PollEvent (&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                running = 0;
                break;

            default:
                break;
        }
    }

}

//Update
void Frame::update()
{
    for (auto o : gameObjects)
        o -> update();
    
    InputManager::flush();
}

//Render
void Frame::render()
{
    SDL_RenderClear (renderer);
    level1 -> draw();
    for (auto o : gameObjects)
        o -> draw();

    SDL_RenderPresent (renderer); 
}

//State
bool Frame::state()
{
    return running;
}

void Frame::clear()
{
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window);
    SDL_Quit();
}