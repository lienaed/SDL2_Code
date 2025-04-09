#pragma once
#include "../Frame.hpp"
#include "../InputManager.hpp"

class GameObject
{
    protected:
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        const double G = 0.2;

    public:    
        GameObject(const char* file, int xpos, int ypos, int destW, int destH);
        virtual void update();
        virtual void draw();
        ~GameObject();

};