#include "GameObject.hpp"

class Player : public GameObject
{
    public:
        void update() override
        {
            destRect.x--;
            destRect.y--;
        }
}