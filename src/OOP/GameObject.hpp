#pragma once
#include "../Frame.hpp"
#include "../InputManager.hpp"

class GameObject
{
    protected:
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        SDL_Rect lastDest;
        SDL_Rect hitbox;
        const double G = 0.3;
        double posX, posY;
        double vX, vY;


    public:
        std::string name;
        std::string tag;
        int jumpState = 0;

        GameObject(const std::string& Name, const std::string& Tag, const char* file, int xpos, int ypos, int destW, int destH);
        ~GameObject();
        
        virtual void update();
        virtual void draw();
        virtual void move(int x, int y);
        
        virtual void onCollision(std::array <char, 3> dir, GameObject* target, int cCheck, int rCheck);

        virtual SDL_Rect getLastDest()
        {
            return lastDest;
        }
        virtual SDL_Rect getRect()
        {
            return destRect;
        }
        virtual SDL_Rect getHitbox()
        {
            return hitbox;
        }
        
        virtual std::string getTag ()
        {
            return tag;
        }
        virtual std::string getName ()
        {
            return name;
        }
};