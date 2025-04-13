#pragma once

#include "GameObject.hpp"


class Map : public GameObject
{
    public:
        Map (const std::string& name, const std::string& tag, const std::string& file)
            : GameObject (name, tag, file, 0, 0, 32, 32);

        void addChunk (const char* file, int num);
        void draw(int shift);

        std::vector <std::vector <int>> map;

    private:
        std::vector <SDL_Texture*> chunks;
        SDL_Rect src, dest;
};