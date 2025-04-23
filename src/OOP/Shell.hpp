#pragma once
#include "GameObject.hpp"

class Shell : public GameObject
{
    private:
        bool dir = 0;
        int counter = 0;

    public:
        Shell (const std::string& name, const std::string& tag, const char* file, int xpos, int ypos, int destW, int destH) 
            : GameObject::GameObject (name, tag, file, xpos, ypos, destW, destH)
        {
            vY = 0;
            vX = 0;
        }

        void update () override;
        void gravity();
};