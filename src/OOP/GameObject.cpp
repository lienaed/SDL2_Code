#include "GameObject.hpp"
#include "../TextureManager.hpp"


GameObject::GameObject(const std::string& name, const std::string& tag, const char* file, int xpos, int ypos, int destW, int destH)
{
    texture = TextureManager::LoadTexture (file);
    
    srcRect = {0, 0, 32, 32};

    destRect.w = destW;
    destRect.h = destH;
    destRect.x = xpos;
    destRect.y = ypos;
    posX = destRect.x;
    posY = destRect.y;

    hitbox = destRect;
}

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

GameObject::~GameObject() 
{
    SDL_DestroyTexture(texture);
}