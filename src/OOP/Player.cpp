#include "Player.hpp"

void Player::update()
{
    if (space)
        jump();
    
    gravity();
    if (destRect.y > Frame::winH - destRect.h)
        destRect.y = Frame::winH - objH;
}

void Player::handelEvent(SDL_Scancode input)
{
    if (input == SDL_SCANCODE_SPACE)
        space = 1;
}

void Player::jump()
{
    if (destRect.y == Frame::winH - objH)
        vY = 5;

    space = 0;
}

void Player::gravity()
{
    vY -= G;
    destRect.y -= vY;
}