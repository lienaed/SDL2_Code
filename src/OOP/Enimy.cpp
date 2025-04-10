#include "Enimy.hpp"

void Enimy::update()
{
    if (dir)
    {
        srcRect.x = 0;
        destRect.x++;
    }
    else
    {
        srcRect.x = 32;
        destRect.x--;
    }

    counter++;
    if (counter == 50)
    {
        counter = 0;
        dir = !dir;
    }
        
    gravity();
}

void Enimy::gravity()
{
    vY -= G;
    destRect.y -= vY;
    if (destRect.y > Frame::winH - destRect.h)
        destRect.y = Frame::winH - destRect.h;
}