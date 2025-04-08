#include "frame.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"
#include "OOP/GameObject.hpp"
#include "OOP/Player.hpp"

SDL_Renderer* Frame::renderer = nullptr;
Map* level1 = new Map();

std::vector <GameObject*> gameObjects;
Player* Knight = nullptr;


Frame::Frame(){}
Frame::~Frame(){}

int map1[20][25] = 
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

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
        level1 -> init (map1);
        Knight = new Player ("assets/Knight.png", 0, 32*9);
        gameObjects.emplace_back (Knight);
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

    while (SDL_PollEvent (&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_KEYDOWN:
                
                switch (event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_ESCAPE:
                        running = 0;
                        break;
                    
                    case SDL_SCANCODE_SPACE:
                        Knight -> handelEvent (event.key.keysym.scancode);
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }

}

//Update
void Frame::update()
{
    SDL_SetRenderDrawColor (renderer, 63, 83, 143, 255);
    for (auto o : gameObjects)
        o -> update();
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