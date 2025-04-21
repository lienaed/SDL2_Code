#include "Map.hpp"
#include "../TextureManager.hpp"

using json = nlohmann::json;

//Load map from JSON
std::vector <std::vector <std::pair<int, int>>> Map::loadMap(const char* path)
{
    std::ifstream file (path);
    json data;
    file >> data;
    std::vector <std::vector <std::pair<int, int>>> map;
    std::map<int, bool> material;

    //Load Textures
    chunks.resize (100);
    int id = 0;
    for (const auto& path : data["chunks"])
    {
        addChunk(path["path"].get <std::string>().c_str(), id);

        std::string tag = path["tag"].get <std::string>();
        if (tag == "solid")
        {
            material[id] = 1;
        }
        else if (tag == "liquid")
        {
            material[id] = 2;
        }
        else if (tag == "gas")
        {
            material[id] = 0;
        }

        id++;
    }

    //Read Map
    for (const auto& row : data["tiles"])
    {
        std::vector <std::pair<int, int>> mapRow;
        for (const auto& tile : row)
        {
            mapRow.emplace_back ((tile), material[tile]);
        }
        map.emplace_back (mapRow);
    }

    std::cout << "Load map: x: " << data["width"] << ", y: " << data["height"] << std::endl;
    return map;
}

//Initialize map
Map::Map (const std::string& name, const std::string& tag, const char* file)
    : GameObject (name, tag, file, 0, 0, 32, 32)
{
    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 25;
    destRect.w = destRect.h = 32;

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
        destRect.y = r * 32;
        for (int c = 0; c < map[0].size(); c++)
        {
            destRect.x = c * 32;
            SDL_RenderCopy (Frame::renderer, chunks[map[r][c].first], &srcRect, &destRect);
        }
    }
}