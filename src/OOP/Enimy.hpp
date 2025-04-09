#include "GameObject.hpp"

class Enimy
{
    private:
        int objW, objH;
        int dir = 0;
        double vY = 0;
        double vX = 1;

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