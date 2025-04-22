#include "CollisionManager.hpp"

char CollisionManager::CharacterCollision(const SDL_Rect& box1, const SDL_Rect& box2, const SDL_Rect& lastDest1, const SDL_Rect& lastDest2)
{
    char result = 'n';
    double interX, interY;
    if (SDL_HasIntersection (&box1, &box2))
    {
        int interX = std::min(box1.x + box1.w, box2.x + box2.w) - std::max(box1.x, box2.x);
        int interY = std::min(box1.y + box1.h, box2.y + box2.h) - std::max(box1.y, box2.y);

        if (interX < interY)
        {
            if (box1.x < box2.x)
                result = 'l';
            else
                result = 'r';
        }
        else
        {
            if (box1.y < box2.y)
                result = 'u';
            else
                result = 'd';
        }

    }
    
    return result;
}

char CollisionManager::MapCollision (const SDL_Rect& box, std::vector <std::vector <std::pair<int, int>>> map)
{
    int lBlock = box.x / 32, rBlock = (box.x + box.w) / 32 + 1;
}