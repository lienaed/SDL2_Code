#include "Frame.hpp"

class Map
{
    public:
        void init (int arr[20][25]);
        void addChunk (const char* file, int num);
        void draw();
    
    private:
        std::vector <SDL_Texture*> chunks;
        SDL_Rect src, dest;
        int map[20][25];
};