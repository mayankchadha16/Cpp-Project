#include "TextureManager.h"
#include "Game.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

SDL_Texture* TextureManager::LoadTexture(const char* texture,SDL_Renderer* renderer){
    SDL_Surface* tempSurface=IMG_Load(texture);
    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}