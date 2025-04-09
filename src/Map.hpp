#pragma once
#include "Frame.hpp"


class Map
{
    public:
        void init (const std::string& file);
        void addChunk (const char* file, int num);
        void draw();
        std::vector <std::vector <int>> map;
    
    private:
        std::vector <SDL_Texture*> chunks;
        SDL_Rect src, dest;
};