#pragma once

#include "Game.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *filename, SDL_Renderer *renderer);
};