#include "GameObject.hpp"
#include "../TextureManager.hpp"


GameObject::GameObject(const std::string& name, const std::string& tag, const char* file, int xpos, int ypos, int destW, int destH)
{
    texture = TextureManager::LoadTexture (file);
    
    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 32;
    destRect.w = destW;
    destRect.h = destH;
    destRect.x = xpos;
    destRect.y = ypos;
    posX = destRect.x;
    posY = destRect.y;
}

void GameObject::update()
{}

void GameObject::draw()
{
    TextureManager::draw (texture, srcRect, destRect);
}

GameObject::~GameObject() 
{
    SDL_DestroyTexture(texture);
}