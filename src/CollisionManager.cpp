#include "CollisionManager.hpp"

//Collision Detect
std::array <char, 3> CollisionManager::Collision(const SDL_Rect& box1, const SDL_Rect& box2, 
    const SDL_Rect& lastDest1, const SDL_Rect& lastDest2)
{
    std::array <char, 3> result = {'n', 'n', 'n'};

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
            result[0] = lastDest1.x < lastDest2.x ? 'l' : 'r';
        }
        else
        {
            result[1] = lastDest1.y < lastDest2.y ? 'u' : 'd';
        }
    }

    return result;
}

//Map Collision
std::array <char, 5> CollisionManager::MapCollision (const SDL_Rect& box, const SDL_Rect& lastDest, Map* m)
{
    std::vector <SDL_Rect> hitboxSet = m->getHitbox();
    std::vector <std::vector <Tile>> map = m->getMap();
    std::vector <int> nearHitboxIndex;

    std::array <char, 5> result = {'n', 'n', 'n'};
    int lBlock = std::max (0, box.x / 32), rBlock = std::min((box.x + box.w - 1) / 32, (int)map[0].size() - 1);
    int uBlock = std::max (0, box.y / 32), dBlock = std::min ((box.y + box.h - 1) / 32, (int)map.size() - 1);
    int xCheck = -1, yCheck = -1;

    for (int r = uBlock; r <= dBlock; r++)
    {
        for (int c = lBlock; c <= rBlock; c++)
        {
            for (auto& i : nearHitboxIndex)
            {
                if (i == map[r][c].hitbox)
                    goto out;
            }
            if (map[r][c] != 0)
                nearHitboxIndex.emplace_back (map[r][c].hitbox);
            out:
        }
    }

    for (int i : nearHitboxIndex)
    {
        SDL_Rect tile = hitboxSet[i];
        auto tmp = CollisionManager::Collision (box, tile, lastDest, tile);

        if (tmp[0] == 'l')
        { 
            result[0] = tmp[0];
            if (xCheck == -1 || hitboxSet[i].x > xCheck)
                xCheck = hitboxSet[i].x;
        }
        else if (tmp[0] == 'r')
        {
            result[0] = tmp[0];
            if (xCheck == -1 || (hitboxSet[i].x + hitboxSet[i].w) < xCheck)
                xCheck = (hitboxSet[i].x + hitboxSet[i].w);
        }

        if (tmp[1] == 'u')
        {
            result[1] = tmp[1];
            if (yCheck == -1 || (hitboxSet[i].y + hitboxSet[i].h) < yCheck)
                yCheck = (hitboxSet[i].y + hitboxSet[i].h);
        }
        else if (tmp[1] == 'd')
        {
            result[1] = tmp[1];
            if (yCheck == -1 || hitboxSet[i].y > yCheck)
                yCheck = hitboxSet[i].y;
        }

        if (map == 2)
            result[2] = 'w';
    }


    result[3] = (char)xCheck;
    result[4] = (char)yCheck;
    return result;
}