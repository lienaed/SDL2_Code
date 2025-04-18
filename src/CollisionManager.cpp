#include "CollisionManager.hpp"

char CollisionManager::CharacterCollision(const SDL_Rect& box1, const SDL_Rect& box2, const SDL_Rect& lastDest1, const SDL_Rect& lastDest2)
{
    char result = 'n';
    double interX, interY;
    if (SDL_HasIntersection (&box1, &box2))
    {
        if (box1.x <= box2.x)
            interX = box1.x + box1.w - box2.x;
        else
            interX = box2.x + box2.w - box1.x;

        if (box1.y <= box2.y)
            interY = box1.y + box1.h - box2.y;
        else
            interY = box2.y + box2.h - box1.y;

        int vY = box1.y - lastDest1.y - (box2.y - lastDest2.y);
        int vX = box1.x - lastDest1.x - (box2.x - lastDest2.x);

        if (!vY || (vX - interX) / vX < (vY - interY) / vY)
        {
            if (lastDest1.x < lastDest2.x)
                result = 'l';
            else
                result = 'r';
        }

        else if (!vX || (vY - interY) / vY <= (vX - interX) / vX)
        {
            if (lastDest1.y < lastDest2.y)
                result = 'u';
            else
                result = 'd';
        }

    }
    
    return result;
}