#pragma once
#include "../Frame.hpp"
#include "../TextureManager.hpp"

class GameObject
{
    protected:
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
    public:    
        GameObject(const char* file, int xpos, int ypos);
        virtual void update();
        virtual void draw();
        ~GameObject();

};