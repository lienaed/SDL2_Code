#include "Enimy.hpp"

void Enimy::update()
{
    if (dir)
    {
        
        
        gravity();
        if (destRect.y > Frame::winH - destRect.h)
            destRect.y = Frame::winH - objH;
    }
}