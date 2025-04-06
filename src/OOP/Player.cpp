#include "Player.hpp"

void Player::update()
{
    if (space)
    {
        destRect.y -= 5;
        space = 0;
    }
}

void Player::handelEvent(SDL_Scancode input)
{
    space = 1;
 }