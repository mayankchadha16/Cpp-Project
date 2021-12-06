#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

// last two args by sarthak
Player::Player(const char *texturesheet, SDL_Renderer *ren, int x, int y, int w, int h, int parts, int rows, int cols)
:GameObject(texturesheet, ren, x, y, w, h, parts, rows, cols) {}

void Player::update()
{
    colControl = (colControl == (animationControl*4 - 1) ? 0 : colControl + 1);
    colNo = colControl/animationControl;
    Keyboard();
    // sarthak starts
    updateDestRect();
    Texture->makeSourceRectangle(rowNo, colNo);
    // sarthak ends
}

void Player::Keyboard()
{
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        last_direction = animate_type = RUN_LEFT;
        xpos -= stepSize;
        flipFlag = true;
        rowNo = 1;
    }

    if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        last_direction = animate_type = RUN_RIGHT;
        xpos += stepSize;
        flipFlag = false;
        rowNo = 1;
    }

    if (currentKeyStates[SDL_SCANCODE_UP])
    {
        last_direction = animate_type = RUN_UP;
        ypos -= stepSize;
    }

    if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
        last_direction = animate_type = RUN_DOWN;
        ypos += stepSize;
    }

    if (!currentKeyStates[SDL_SCANCODE_RIGHT] && !currentKeyStates[SDL_SCANCODE_LEFT] && !currentKeyStates[SDL_SCANCODE_DOWN] && !currentKeyStates[SDL_SCANCODE_UP])
    {
        animate_type = IDLE;
        rowNo = 0;
    }
    if (xpos < 0)
        xpos = 0;
    else if (xpos > 800)
        xpos = 800;
    if (ypos < 0)
        ypos = 0;
    else if (ypos > 800)
        ypos = 800;
}

void Player::Render()
{
    GameObject::Render(flipFlag);
}