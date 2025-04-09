#include "Map.hpp"
#include "TextureManager.hpp"

using json = nlohmann::json;

//Load map from JSON
std::vector <std::vector <int>> loadMap(const std::string& path)
{
    std::ifstream file (path);
    json data;
    file >> data;
    std::vector <std::vector <int>> map;
    for (const auto& row : data["tiles"])
    {
        std::vector <int> mapRow;
        for (const auto& tile : row)
        {
            mapRow.push_back (tile);
        }
        map.push_back (mapRow);
    }
    std::cout << "Load map: x: " << data["width"] << ", y: " << data["height"] << std::endl;
    return map;
}

//Initialize map
void Map::init(const std::string& file)
{
    chunks.resize (100);
    Map::addChunk ("assets/Sky.png", 0);
    Map::addChunk ("assets/Dirt.png", 1);
    Map::addChunk ("assets/Grass.png", 2);
    Map::addChunk ("assets/Water.png", 3);
    
    src.x = src.y = 0;
    src.w = src.h = 25;
    dest.w = dest.h = 32;

    map = loadMap(file);
}

//Add texture
void Map::addChunk (const char* file, int num)
{
    chunks[num] = TextureManager::LoadTexture (file);
}

//Draw map
void Map::draw()
{
    for (int r = 0; r < map.size(); r++)
    {
        dest.y = r * 32;
        for (int c = 0; c < map[0].size(); c++)
        {
            dest.x = c * 32;
            SDL_RenderCopy (Frame::renderer, chunks[map[r][c]], &src, &dest);
        }
    }
}