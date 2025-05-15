#pragma once

#include "GameObject.hpp"

struct Tile 
{
    int texture;
    int type;
    int hitbox;
    Tile (int t, int y, int h) : texture(t), type(y), hitbox(h) {};
};

class Map : public GameObject
{
    public:
        Map (const std::string& name, const std::string& tag, const char* file);

        
        void addChunk (const char* file, int label);
        void draw() override;
        const std::vector <std::vector <Tile>>& getMap() const
        {
            return map;
        }
        static SDL_Rect getTileBox(int c, int r)
        {
            SDL_Rect tile = {c*32, r*32, 32, 32};
            return tile;
        }
        const std::vector <SDL_Rect>& getHitbox() const
        {
            return hitboxSet;
        }

    protected:
        std::vector <SDL_Texture*> chunks;
        std::vector <std::vector <Tile>> map;
        std::vector <SDL_Rect> hitboxSet;

        std::vector <std::vector <Tile>> loadMap(const char* path);
        std::vector <SDL_Rect> makeHitbox();
}; 