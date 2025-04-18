#include "Frame.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"
#include "CollisionManager.hpp"

#include "ObjectManager.hpp"
#include "OOP/GameObject.hpp"
#include "OOP/Map.hpp"
#include "OOP/Player.hpp"
#include "OOP/Shell.hpp"

//Create renderer and managers
SDL_Renderer* Frame::renderer = nullptr;
ObjectManager objectManager;

//Other variables
int Frame::winW = 0, Frame::winH = 0;

//Constructor and destructor
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

        //Objects Initialization
        objectManager.addObject (new Map ("Level1", "Map", "assets/Maps/Level1.json"));
        objectManager.addObject (new Player ("Player", "Friendly", "assets/Knight.png", 0, winH, 64, 64));
        objectManager.addObject (new Shell ("Shell", "Enimy", "assets/Shell.png", 300, winH, 64, 64));

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
    objectManager.updateAll();

    auto* p = objectManager.findObject ("Player");
    std::cout << p << std::endl;
    for (auto* o : objectManager.findObjectType ("Enimy"))
    {
        char result = CollisionManager::CharacterCollision (p->getHitbox(), p->getFormerRect(), o->getHitbox(), o->getFormerRect());
        if (result != 'n')
        {
            if (Player* player = dynamic_cast <Player*> (p))
                player->onCollision(result, o);
        }
    }
    
    InputManager::flush();
}

//Render
void Frame::render()
{
    SDL_RenderClear (renderer);
    
    objectManager.drawAll();

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