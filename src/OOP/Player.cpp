#include "Player.hpp"

void Player::update()
{
    formerDest = destRect;
    
    handelEvent();
    gravity();
    move(posX, posY);
    hitbox = destRect;
}

//Process Inputs
void Player::handelEvent()
{
    if (InputManager::keyPress (SDL_SCANCODE_SPACE))
        jump();
    
    if (InputManager::keyDown (SDL_SCANCODE_D))
        moveRight();
    
    if (InputManager::keyDown (SDL_SCANCODE_A))
        moveLeft();
}

//Movements
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
//End Movements

//Enimy Collision Detect
void Player::onCollision(char dir, GameObject* target)
{
    std::cout << "Interact" << std::endl;
    SDL_Rect targetBox = target->getHitbox();
    switch (dir)
    {
        case 'l':
            posX = targetBox.x - destRect.w;
            break;
        
        case 'r':
            posX = targetBox.x + targetBox.w;
            break;
        
        case 'u':
            posY = targetBox.y - destRect.h;
            break;
        
        case 'd':
            posY = targetBox.y + targetBox.h;
            break;
    }
    move(posX, posY);
}