#include "CollisionManager.hpp"

char CollisionManager::CharacterCollision(const SDL_Rect& box1, const SDL_Rect& box2, const SDL_Rect& lastDest1, const SDL_Rect& lastDest2)
{
     char result = 'n';

    if (SDL_HasIntersection(&box1, &box2)) 
    {
        int dx1 = box1.x - lastDest1.x;
        int dy1 = box1.y - lastDest1.y;
        int dx2 = box2.x - lastDest2.x;
        int dy2 = box2.y - lastDest2.y;

        int vX = dx1 - dx2;
        int vY = dy1 - dy2;

        int interWidth  = std::min(box1.x + box1.w, box2.x + box2.w) - std::max(box1.x, box2.x);
        int interHeight = std::min(box1.y + box1.h, box2.y + box2.h) - std::max(box1.y, box2.y);

        if (interWidth < interHeight)
        {
            // 横向碰撞
            result = lastDest1.x < lastDest2.x ? 'l' : 'r';
        }
        else
        {
            // 纵向碰撞
            result = lastDest1.y < lastDest2.y ? 'u' : 'd';
        }
    }

    return result;
}

char CollisionManager::MapCollision (const SDL_Rect& box, std::vector <std::vector <std::pair<int, int>>> map)
{
    int lBlock = box.x / 32, rBlock = (box.x + box.w) / 32 + 1;
    int uBlock = box.y / 32, dBlock = (box.y + box.h) / 32 + 1;
    for (int r = uBlock; r <= dBlock; r++)
    {
        for (int c = lBlock; c <= rBlock; c++)
        {
            if (map[r][c].second == 1)
            {
                
            }
        }
    }
}