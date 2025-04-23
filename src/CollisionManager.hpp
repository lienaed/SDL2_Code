#pragma once
#include "Frame.hpp"
#include "ObjectManager.hpp"
#include "OOP/GameObject.hpp"
#include "OOP/Map.hpp"
#include "OOP/Player.hpp"
#include "OOP/Shell.hpp"

class CollisionManager
{
    private:

    public:
        static char CharacterCollision (const SDL_Rect& box1, const SDL_Rect& box2, const SDL_Rect& lastDest1, const SDL_Rect& lastDest2);
        //static char MapCollision (const SDL_Rect& box, std::vector <std::vector <std::pair<int, int>>> map);

};