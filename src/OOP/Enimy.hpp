#pragma once
#include "GameObject.hpp"

class Enimy : public GameObject
{
    private:
        bool dir = 0;
        vY = 0;
        vX = 1;
        int counter = 0;

    public:
        Enimy (const std::string& name, const std::string& tag, const char* file, int xpos, int ypos, int destW, int destH) 
            : GameObject::GameObject (name, tag, file, xpos, ypos, destW, destH)
        {}

        void update () override;
        void gravity();
};