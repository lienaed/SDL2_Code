#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
    private:
        bool space = 0;

    public:
        Player (const std::string& name, const std::string& tag, const char* file, int xpos, int ypos, int destW, int destH) 
            : GameObject::GameObject (name, tag, file, xpos, ypos, destW, destH) 
        {        
            vY = 7;
            vX = 2.5;
        }
        
        void update() override; 
        void handelEvent();
        void jump();
        void gravity();
        void moveRight();
        void moveLeft();
        void onCollision(char dir, GameObject* target);
};