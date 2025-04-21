#include "Shell.hpp"

void Shell::update()
{
    lastDest = destRect;
    
    if (dir)
    {
        srcRect.x = 0;
        posX += vX;
    }
    else
    {
        srcRect.x = 32;
        posX -= vX;
    }

    counter++;
    if (counter == 50)
    {
        counter = 0;
        dir = !dir;
    }
        
    gravity();
    move(posX, posY);
    hitbox = destRect;
}

void Shell::gravity()
{
    vY -= G;
    posY -= vY;
    if (posY > Frame::winH - destRect.h)
        posY = Frame::winH - destRect.h;
}