#include "Player.hpp"

void Player::update()
{
    formerDest = destRect;
    
    if (InputManager::keyPress (SDL_SCANCODE_SPACE))
        jump();
    
    if (InputManager::keyDown (SDL_SCANCODE_D))
        moveRight();
    
    if (InputManager::keyDown (SDL_SCANCODE_A))
        moveLeft();
    
    gravity();
    move(posX, posY);
}

void Player::jump()
{
    if (posY == Frame::winH - destRect.h)
        vY = 5;

    space = 0;
}

void Player::gravity()
{
    vY -= G;
    posY -= vY;
    if (posY > Frame::winH - destRect.h)
        posY = Frame::winH - destRect.h;
}

void Player::moveRight()
{
    posX += vX;
}

void Player::moveLeft()
{
    posX -= vX;
}