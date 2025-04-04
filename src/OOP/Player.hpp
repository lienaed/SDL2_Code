#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
    private:
        bool space = 0;


    public:
        Player (const char* file, int x, int y) : GameObject::GameObject (file, x, y)
        {}

        void update() override
        {
            if (space)
            {
                destRect.y -= 5;
                space = 0;
            }
        }

        void handelEvent(SDL_Scancode input)
        {
           space = 1;
        }
};