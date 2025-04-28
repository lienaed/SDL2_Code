#pragma once

#include "GameObject.hpp"


class Map : public GameObject
{
    public:
        Map (const std::string& name, const std::string& tag, const char* file);

        void addChunk (const char* file, int num);
        void draw() override;
        
        const std::vector <std::vector <std::pair<int, int>>>& getMap() const
        {
            return map;
        }

        const SDL_Rect getTileBox(int c, int r) const
        {
            SDL_Rect tile = {c*32, r*32, 32, 32};
            return tile;
        }

    protected:
        std::vector <SDL_Texture*> chunks;
        std::vector <std::vector <std::pair<int, int>>> map;
        std::vector <std::vector <std::pair<int, int>>> loadMap(const char* path);
}; 