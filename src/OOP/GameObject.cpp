#include "GameObject.hpp"
#include "../TextureManager.hpp"
#include "Map.hpp"


GameObject::GameObject(const std::string& Name, const std::string& Tag, const char* file, int xpos, int ypos, int destW, int destH)
{
    texture = TextureManager::LoadTexture (file);

    name = Name;
    tag = Tag;
    
    srcRect = {0, 0, 32, 32};
    destRect.w = destW;
    destRect.h = destH;
    destRect.x = xpos;
    destRect.y = ypos;
    posX = destRect.x;
    posY = destRect.y;

    hitbox = destRect;
}

//Update
void GameObject::update()
{}

void GameObject::draw()
{
    TextureManager::draw (texture, srcRect, destRect);
}

void GameObject::move(int x, int y)
{
    destRect.x = static_cast <int> (x);
    destRect.y = static_cast <int> (y);
}

//Collision Reaction
void GameObject::onCollision(std::array <char, 3> dir, GameObject* target, int cCheck, int rCheck)
{
    SDL_Rect targetBoxH;
    SDL_Rect targetBoxV;
    //Enimy Case
    if (cCheck == -1 && rCheck == -1)
    {
        targetBoxH = target->getHitbox ();
        targetBoxV = target->getHitbox ();
    }
    //Map Case
    else
    {
        Map* m = dynamic_cast <Map*> (target);
        targetBoxH = m->getTileBox (cCheck, 0);
        targetBoxV = m->getTileBox (0, rCheck);
        std::cout << "Map Collision.";
    }   

    std::cout << dir[0] << ' ' << dir[1] << ' ' << dir[2] << ' ' << this->moveState << std::endl;
    
    switch (dir[1])
    {
        case 'u':
            vY = 0;
            posY = targetBoxV.y - destRect.h + 1;
            //std::cout << "u" << std::endl;
            break;
        
        case 'd':
            vY = 0;
            posY = targetBoxV.y + targetBoxV.h - 1;
            //std::cout << "d" << std::endl;
            break;
        
        case 'n':
            break;
    }
    switch (dir[0])
    {
        case 'l':
            vX = 0;
            posX = targetBoxH.x - destRect.w + 1;
            //std::cout << "l" << std::endl;
            break;
        
        case 'r':
            vX = 0;
            posX = targetBoxH.x + targetBoxH.w - 1;
            //std::cout << "r" << std::endl;
            break;
    }

    move(posX, posY);
}

GameObject::~GameObject() 
{
    SDL_DestroyTexture(texture);
}