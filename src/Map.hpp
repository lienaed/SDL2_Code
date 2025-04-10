#pragma once
#include "Frame.hpp"


class Map
{
    public:
        Map (const std::string& file);
        void addChunk (const char* file, int num);
        void draw(int shift);
        std::vector <std::vector <int>> map;
    
    private:
        std::vector <SDL_Texture*> chunks;
        SDL_Rect src, dest;
};