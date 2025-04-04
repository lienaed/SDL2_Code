#include "GameObject.hpp"

class Player : public GameObject
{
    public:
        Player (const char* file, int x, int y) : GameObject::GameObject (file, x, y)
        {

        }

        void update() override
        {
            destRect.x++;
        }
};