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
void Player::onCollision(std::array <char, 3> dir, GameObject* target, int cCheck, int rCheck)
{
    //Enimy Case
    if (cCheck == rCheck == -1)
    {
        SDL_Rect targetBox1 = target->getHitbox ();
        SDL_Rect targetBox2 = target->getHitbox ();
    }
    //Map Case
    else
    {
        Map* m = dynamic_cast <Map*> (target);
        SDL_Rect targetBox1 = m->getTileBox (0, cCheck);
        SDL_Rect targetBox2 = m->getTileBox (rCheck, 0);
    }

    std::cout << dir[0] << ' ' << dir[1] << ' ' << dir[2] << std::endl;
    

    switch (dir[0])
    {
        case 'l':
            posX = targetBox1.x - destRect1.w;
            //std::cout << "l" << std::endl;
            break;
        
        case 'r':
            posX = targetBox1.x + targetBox1.w;
            //std::cout << "r" << std::endl;
            break;
    }
    switch (dir[1])
    {
        case 'u':
            posY = targetBox2.y - destRect2.h;
            //std::cout << "u" << std::endl;
            break;
        
        case 'd':
            posY = targetBox2.y + targetBox2.h;
            //std::cout << "d" << std::endl;
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