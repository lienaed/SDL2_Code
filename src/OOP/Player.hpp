#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
    private:
        bool space = 0;
        
        double vY = 7;
        double vX = 2.5;

    public:
        Player (const std::string& name, const std::string& tag, const char* file, int xpos, int ypos, int destW, int destH) 
            : GameObject::GameObject (name, tag, file, xpos, ypos, destW, destH) 
        {}
        
        void update() override; 
        void handelEvent(SDL_Scancode input);
        void jump();
        void gravity();
        void moveRight();
        void moveLeft();
};