#pragma once
#include "../Frame.hpp"
#include "../TextureManager.hpp"

class GameObject
{
    protected:
        int x, y;
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
    public:    
        void GameObject(const char* file, int x, int y)
        virtual void update();
        virtual void draw()
        {
            TextureManager::draw (texture, srcRect, destRect);
        }
        virtual void render();
        virtual void ~GameObject(){}

};