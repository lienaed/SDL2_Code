#pragma once
#include "../Frame.hpp"
#include "../InputManager.hpp"

class GameObject
{
    protected:
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        SDL_Rect hitbox;
        const double G = 0.3;
        double posX, posY;

    public:
        std::string name;
        std::string tag;

        GameObject(const std::string& name, const std::string& tag, const char* file, int xpos, int ypos, int destW, int destH);
        virtual void update();
        virtual void draw();
        virtual SDL_Rect getRect()
        {
            return destRect;
        }
        ~GameObject();

};