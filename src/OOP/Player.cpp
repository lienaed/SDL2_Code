#include "Player.hpp"
#include "Map.hpp"

void Player::update()
{
    lastDest = destRect;
    
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
            vY = 10;

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
void Player::onCollision(std::array <char, 3> dir, GameObject* target)
{
    if (Map* m = dynamic_cast <Map*> (target))
        SDL_Rect targetBox = m->getTileBox()
        
    SDL_Rect targetBox = target->getHitbox();

    std::cout << dir[0] << ' ' << dir[1] << ' ' << dir[2] << std::endl;
    switch (dir[0])
    {
        case 'l':
            posX = targetBox.x - destRect.w;
            //std::cout << "l" << std::endl;
            break;
        
        case 'r':
            posX = targetBox.x + targetBox.w;
            //std::cout << "r" << std::endl;
            break;
    }
    switch (dir[1])
    {
        case 'u':
            posY = targetBox.y - destRect.h;
            //std::cout << "u" << std::endl;
            break;
        
        case 'd':
            posY = targetBox.y + targetBox.h;
            //std::cout << "d" << std::endl;
            break;
    }
    // switch (dir[2])
    // {
    //     case 'n':
    //         vX = 5;
    //         vY = 7;
    //         //std::cout << "u" << std::endl;
    //         break;
        
    //     case 'w':
    //         vX = 3;
    //         vY = 4;
    //         //std::cout << "d" << std::endl;
    //         break;
    // }    

    move(posX, posY);
}