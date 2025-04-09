#include "InputManager.hpp"


const Uint8* InputManager::pressedKeys = nullptr;
Uint8 InputManager::previousKeys[SDL_NUM_SCANCODES] = {0};


void InputManager::update ()
{
    pressedKeys = SDL_GetKeyboardState (nullptr);
}

bool InputManager::keyDown (SDL_Scancode key)
{
    return pressedKeys[key];
}

bool InputManager::keyPress (SDL_Scancode key)
{
    return pressedKeys[key] && !previousKeys[key];
}

void InputManager::flush()
{
    SDL_Event a;
    while (SDL_PollEvent (&a)){}

    for (int i = 0; i < SDL_NUM_SCANCODES; i++)
        previousKeys[i] = pressedKeys[i];
}