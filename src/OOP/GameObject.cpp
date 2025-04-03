#include "GameObject.hpp"

void GameObject::Gameobject(const char* file, int xpos, int ypos)
{
    texture = TextureManager::LoadTexture (file);
    x = xpos;
    y = ypos;
    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 25;
    destRect.w = destRect.h = 64;
}

void GameObject::render()
{
    SDL_RenderCopy (Frame::renderer, texture, &srcRect, &destRect);
}

GameObject::~GameObject() {
    SDL_DestroyTexture(texture);
}