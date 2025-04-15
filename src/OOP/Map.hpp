#pragma once

#include "GameObject.hpp"


class Map : public GameObject
{
    public:
        Map (const std::string& name, const std::string& tag, const char* file);

        void addChunk (const char* file, int num);
        void draw() override;
        std::vector <std::vector <int>> loadMap(const char* path);

    protected:
        static std::vector <SDL_Texture*> chunks;
        static std::vector <std::vector <int>> map;
};  