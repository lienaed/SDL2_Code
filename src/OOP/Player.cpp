#include "Player.hpp"
#include "Map.hpp"

void Player::update()
{
    lastDest = destRect;

    handelEvent();
    gravity();
    correction();
    move(posX, posY);

    hitbox = destRect;
}

//Process Inputs
void Player::handelEvent()
{
    if (moveState == 1)
    {
        if (InputManager::keyPress (SDL_SCANCODE_SPACE))
            jump();
    }

    if (InputManager::keyDown (SDL_SCANCODE_D))
        moveRight();
    
    if (InputManager::keyDown (SDL_SCANCODE_A))
        moveLeft();
}

//Movements
    void Player::jump()
    {
        vY = 10;
    }

    void Player::gravity()
    {
        vY -= G;
        posY -= vY;
    } 

    void Player::moveRight()
    {
        vX = 5;
        posX += vX;
    }

    void Player::moveLeft()
    {
        vX = 5;
        posX -= vX;
    }

    void Player::correction()
    {
        if (posY < 0)
        {
            posY = 0;
            vY = 0;
        }
        else if (posY > Frame::winH - destRect.h)
        {
            vY = 0;
            posY = Frame::winH - destRect.h;
        }

        if (posX < 0)
        {
            posX = 0;
            vX = 0;
        }
        else if (posX > Frame::winW - destRect.w)
        {
            posX = Frame::winW - destRect.w;
            vX = 0;
        }
    }
//End Movements
