#pragma once
#include "Frame.hpp"

class InputManager
{
    private:
        static const Uint8* pressedKeys;
        static Uint8 previousKeys [SDL_NUM_SCANCODES];

    public:
        static void update();
        static bool keyPress(SDL_Scancode key);
        static bool keyDown(SDL_Scancode key);
        static void flush();

};