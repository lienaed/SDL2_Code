#include "Map.hpp"
#include "TextureManager.hpp"

void Map::init(int arr[20][25])
{
    Map::addChunk ("assets/Water.png");
    Map::addChunk ("assets/Dirt.png");
    Map::addChunk ("assets/Grass.png");
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

void Map::addChunk (const char* file)
{
    chunks.emplace_back (TextureManager::LoadTexture (file));
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