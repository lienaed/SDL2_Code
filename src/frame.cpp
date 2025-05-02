#include "Frame.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"
#include "CollisionManager.hpp"

#include "ObjectManager.hpp"
#include "OOP/GameObject.hpp"
#include "OOP/Map.hpp"
#include "OOP/Player.hpp"
#include "OOP/Shell.hpp"

//Create renderer and manager
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
        objectManager.addObject (new Player ("Player", "Friendly", "assets/Knight.png", 0, 0, 64, 64));
        objectManager.addObject (new Shell ("Shell", "Enimy", "assets/Shell.png", 300, 0, 64, 64));

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
    timer++;
    std::cout << timer << std::endl;

    objectManager.updateAll();

    //Collision Update
    std::array <char, 3> result; 
    auto* playerObj = objectManager.findObject ("Player");
    auto* mapObj = objectManager.findObject ("Level1");
    if (!playerObj || !mapObj)
        return;
    
    Player* p = dynamic_cast <Player*> (playerObj);
    Map* m = dynamic_cast <Map*> (mapObj);
    if (!p || !m)
        return;

    //Enimy Collision Detect
    for (auto* e : objectManager.findObjectType ("Enimy"))
    {
        result = CollisionManager::Collision (p->getHitbox(), e->getHitbox(), p->getLastDest(), e->getLastDest());

        if (result[0] != 'n' || result[1] != 'n' || result[2] != 'n')
        {
            p->onCollision(result, e, -1, -1);
        }

        //Map Collision Detect
        std::array <char, 5> CollInfo = CollisionManager::MapCollision (e->getHitbox(), e->getLastDest(), m->getMap());
        result[0] = CollInfo[0];
        result[1] = CollInfo[1];
        result[2] = CollInfo[2];
        int cCheck = (int)CollInfo[3];
        int rCheck = (int)CollInfo[4];

        if (result[0] != 'n' || result[1] != 'n' || result[2] != 'n')
            e->onCollision (result, m, cCheck, rCheck);
    }

    //Map Collision Detect
    std::array <char, 5> CollInfo = CollisionManager::MapCollision (p->getHitbox(), p->getLastDest(), m->getMap());
    result[0] = CollInfo[0];
    result[1] = CollInfo[1];
    result[2] = CollInfo[2];
    int cCheck = (int)CollInfo[3];
    int rCheck = (int)CollInfo[4];

    if (result[0] != 'n' || result[1] != 'n' || result[2] != 'n')
        p->onCollision (result, m, cCheck, rCheck);

    if (result[1] == 'u')
        p->moveState = 1;
    else
        p->moveState = 0;


    //Clean InputManager Events
    InputManager::flush();
}

// //Update
// void Frame::update()
// {
//     objectManager.updateAll();

//     //Collision Update
//     std::array <char, 3> result; 
//     auto* p = objectManager.findObject ("Player");
//     auto* mapObj = objectManager.findObject ("Level1");
//     Map* m = dynamic_cast <Map*> (mapObj);

//     std::vector <GameObject*> enimies = objectManager.findObjectType ("Enimy");
//     std::vector <GameObject*> characters = objectManager.findObjectType ("Friendly");
//     std::vector <GameObject*> entities = enimies;
//     entities.insert (entities.end(), characters.begin(), characters.end());
    
//     //Map Collision Detect
//     for (auto* e : characters)
//     {
//         std::array <char, 5> CollInfo = CollisionManager::MapCollision (e->getHitbox(), e->getLastDest(), m->getMap());
//         result[0] = CollInfo[0];
//         result[1] = CollInfo[1];
//         result[2] = CollInfo[2];
//         int cCheck = (int)CollInfo[3];
//         int rCheck = (int)CollInfo[4];

//         if (result[0] != 'n' || result[1] != 'n' || result[2] != 'n')
//             e->onCollision (result, m, cCheck, rCheck);
//     }

//     //Enimy Collision Detect
//     for (auto* e : entities)
//     {
//         result = CollisionManager::Collision (p->getHitbox(), e->getHitbox(), p->getLastDest(), e->getLastDest());

//         if (result[0] != 'n' || result[1] != 'n' || result[2] != 'n')
//         {   
//             p->onCollision(result, e, -1, -1);
//         }
//     }

//     //Clean InputManager Events
//     InputManager::flush();
// }

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