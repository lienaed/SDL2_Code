#pragma once
#include "../Frame.hpp"
#include "../InputManager.hpp"

class GameObject
{
    protected:
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        SDL_Rect formerDest;
        SDL_Rect hitbox;
        const double G = 0.3;
        double posX, posY;
        double vX, vY;

    public:
        std::string name;
        std::string tag;

        GameObject(const std::string& name, const std::string& tag, const char* file, int xpos, int ypos, int destW, int destH);
        ~GameObject();
        
        virtual void update();
        virtual void draw();
        virtual void move(int x, int y);
        
        virtual SDL_Rect getFormerRect()
        {
            return formerDest;
        }

        virtual SDL_Rect getRect()
        {
            return destRect;
        }
        virtual SDL_Rect getHitbox()
        {
            return hitbox;
        }
};