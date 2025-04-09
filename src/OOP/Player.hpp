#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
    private:
        bool space = 0;
        
        double vY = 7;
        double vX = 2.5;
        int objH, objW;

    public:
        Player (const char* file, int xpos, int ypos, int destW, int destH) 
            : GameObject::GameObject (file, xpos, ypos, destW, destH) 
        {
            objW = destW;
            objH = destH;
        }
        void update() override; 
        void handelEvent(SDL_Scancode input);
        void jump();
        void gravity();
        void moveRight();
        void moveLeft();
};