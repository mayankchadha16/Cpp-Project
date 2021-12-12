#pragma once

#include "Game.h"
#include "TextureManager.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
class GameObject
{
public:
    GameObject(const char *texturesheet, int x, int y, int w, int h, int parts, int rows, int cols);
    ~GameObject();

    void update();
    void Render(bool flipFlag = false);

    // sarthak starts
    void updateDestRect();
    // sarthak ends

protected:
    int xpos, ypos;
    // sarthak starts
    TextureManager* Texture;
    int width , height;
    // is null if we don't clip, specifies the dest rect
    SDL_Rect destRect;
    // stepSize
    int stepSize = 3;
    // camera control
    // sarthak ends
};