#include "Player.hpp"

Player::update()
{
    if (space)
    {
        destRect.y -= 5;
        space = 0;
    }
}

Player::handelEvent(SDL_Scancode input)
{
    space = 1;
 }