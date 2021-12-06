#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y, int w, int h, int parts, int rows, int cols) // last five args by sarthak
{
    xpos = x;
    ypos = y;

    // sarthak starts
    Texture = new TextureManager();
    Texture->loadTexture(texturesheet, parts, rows, cols);
    width = w;
    height = h;
    // make the destination rectangle
    destRect = {xpos, ypos, width, height};
    // sarthak ends
}

void GameObject::update()
{
    // sarthak starts
    updateDestRect();
    // sarthak ends
}

void GameObject::Render(bool flipFlag)
{
    // sarthak starts
    Texture->render(&destRect, flipFlag);
    // sarthak ends
}

// sarthak starts
void GameObject::updateDestRect() {
    destRect.x = xpos;
    destRect.y = ypos;
}
// sarthak ends