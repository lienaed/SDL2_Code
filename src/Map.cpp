#include "Map.hpp"

void Map::init(int arr[20][25])
{
    chunks.resize (100);
    Map::addChunk ("assets/Sky.png", 0);
    Map::addChunk ("assets/Dirt.png", 1);
    Map::addChunk ("assets/Grass.png", 2);
    Map::addChunk ("assets/Water.png", 3);
    
    src.x = src.y = 0;
    src.w = src.h = 25;
    dest.w = dest.h = 32;

    for (int r = 0; r < 20; r++)
    {
        for (int c = 0; c < 25; c++)
        {
            map[r][c] = arr[r][c];
        }
    }
}

void Map::addChunk (const char* file, int num)
{
    chunks[num] = TextureManager::LoadTexture (file);
}

void Map::draw()
{
    for (int r = 0; r < 20; r++)
    {
        dest.y = r * 32;
        for (int c = 0; c < 25; c++)
        {
            dest.x = c * 32;
            SDL_RenderCopy (Frame::renderer, chunks[map[r][c]], &src, &dest);
        }
    }
}