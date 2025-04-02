#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* file)
{
    SDL_Surface* surface = IMG_Load (file);
    if (surface)
        std::cout << file << " texture created." << std::endl;
    else
        std::cout << file << " texture creating failed" << std::endl;

    SDL_Texture* tex = SDL_CreateTextureFromSurface (Frame::renderer, surface);
    SDL_FreeSurface (surface);
    return tex;
}

void TextureManager::draw (SDL_Texture* tex, SDL_Rect srcR, SDL_Rect destR)
{
    SDL_RenderCopy (Frame::renderer, tex, &srcR, &destR);
} 