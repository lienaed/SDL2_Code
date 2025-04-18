#pragma once

#include "GameObject.hpp"


class Map : public GameObject
{
    public:
        Map (const std::string& name, const std::string& tag, const char* file);

        void addChunk (const char* file, int num);
        void draw() override;

    protected:
        std::vector <SDL_Texture*> chunks;
        std::vector <std::vector <int>> map;
        std::vector <std::vector <int>> loadMap(const char* path);
}; 