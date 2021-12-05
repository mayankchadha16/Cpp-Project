#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    xpos = x;
    ypos = y;
}

void GameObject::update(int descw, int desch)
{
    // xpos++;
    // ypos++;
    srcRect.h = 820;
    srcRect.w = 820;

    srcRect.x = 0;
    srcRect.y = 0;

    descRect.x = xpos;
    descRect.y = ypos;
    descRect.w = descw;
    descRect.h = desch;
}

void GameObject::Render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &descRect);
}