#pragma once
#include "GameObject.hpp"

class Enimy : public GameObject
{
    private:
        int objW, objH;
        bool dir = 0;
        double vY = 0;
        double vX = 1;
        int counter = 0;

    public:
        Enimy (const char* file, int xpos, int ypos, int destW, int destH) 
            : GameObject::GameObject (file, xpos, ypos, destW, destH)
        {
            objW = destW;
            objH = destH;
        }

        void update () override;
        void gravity();
};