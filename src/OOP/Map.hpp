#pragma once
#include "Frame.hpp"
#include "GameObject.hpp"


class Map : public GameObject
{
    public:
        Map (const std::string& name, const std::string& tag, const std::string& file, int xpos, int ypos, int destW, int destH)
            : GameObject::GameObject (name, tag, file, xpos, ypos, destW, destH);
        void addChunk (const char* file, int num);
        void draw(int shift);
        std::vector <std::vector <int>> map;

    private:
        std::vector <SDL_Texture*> chunks;
        SDL_Rect src, dest;
};