#include "GameObject.hpp"


GameObject::GameObject(const char* file, int xpos, int ypos)
{
    texture = TextureManager::LoadTexture (file);
    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 25;
    destRect.w = destRect.h = 64;
    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::update()
{

}

void GameObject::draw()
{
    TextureManager::draw (texture, srcRect, destRect);
}

GameObject::~GameObject() {
    SDL_DestroyTexture(texture);
}