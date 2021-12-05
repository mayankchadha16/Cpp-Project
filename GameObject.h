#pragma once

#include "Game.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
class GameObject
{
public:
    GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y);
    ~GameObject();

    void update(int,int);
    void Render(bool flipFlag = false);

protected:
    int xpos, ypos;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, descRect;
    SDL_Renderer *renderer;
};