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


//Map/Enimy Collision Detect
void Player::onCollision (std::array <char, 3> dir, GameObject* target, int cCheck, int rCheck)
{
    SDL_Rect targetBoxH;
    SDL_Rect targetBoxV;
    //Enimy Case
    if (cCheck == -1 && rCheck == -1)
    {
        targetBoxH = target->getHitbox ();
        targetBoxV = target->getHitbox ();
    }
    //Map Case
    else
    {
        // Map* m = dynamic_cast <Map*> (target);
        // targetBoxH = m->getTileBox (0, cCheck);
        // targetBoxV = m->getTileBox (rCheck, 0);
        std::cout << "Map Collision." << std::endl;
        std::cout << dir[0] << ' ' << dir[1] << ' ' << dir[2] << std::endl;
        return;
    }

    std::cout << dir[0] << ' ' << dir[1] << ' ' << dir[2] << std::endl;
    
    switch (dir[1])
    {
        case 'u':
            posY = targetBoxV.y - destRect.h;
            //std::cout << "u" << std::endl;
            break;
        
        case 'd':
            posY = targetBoxV.y + targetBoxV.h;
            //std::cout << "d" << std::endl;
            break;
    }
    switch (dir[0])
    {
        case 'l':
            posX = targetBoxH.x - destRect.w;
            //std::cout << "l" << std::endl;
            break;
        
        case 'r':
            posX = targetBoxH.x + targetBoxH.w;
            //std::cout << "r" << std::endl;
            break;
    }

    move(posX, posY);
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
}