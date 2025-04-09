#include "Player.hpp"

void Player::update()
{
    if (InputManager::keyPress (SDL_SCANCODE_SPACE))
        jump();
    
    if (InputManager::keyDown (SDL_SCANCODE_D))
        moveRight();
    
    if (InputManager::keyDown (SDL_SCANCODE_A))
        moveLeft();
    
    gravity();
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
    if (destRect.y > Frame::winH - destRect.h)
        destRect.y = Frame::winH - objH;
}

void Player::moveRight()
{
    destRect.x += vX;
}

void Player::moveLeft()
{
    destRect.x -= vX;
}