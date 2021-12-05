#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

Player::Player(const char *texturesheet, SDL_Renderer *ren, int x, int y):GameObject(texturesheet, ren,x,y)
{
   
}

void Player::update(int descw, int desch)
{
    Keyboard();
    // dest_rect.x = xpos;
    // dest_rect.y = ypos;
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

void Player::Keyboard()
{
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        last_direction = animate_type = RUN_LEFT;
        xpos--;
    }

    if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        last_direction = animate_type = RUN_RIGHT;
        xpos++;
    }

    if (currentKeyStates[SDL_SCANCODE_UP])
    {
        last_direction = animate_type = RUN_UP;
        ypos--;
    }

    if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
        last_direction = animate_type = RUN_DOWN;
        ypos++;
    }

    if (currentKeyStates[SDL_SCANCODE_RIGHT] and currentKeyStates[SDL_SCANCODE_UP])
    {
        last_direction = animate_type = RUN_RIGHT_UP;
        xpos++;
        ypos--;
    }

    if (currentKeyStates[SDL_SCANCODE_LEFT] and currentKeyStates[SDL_SCANCODE_UP])
    {
        last_direction = animate_type = RUN_LEFT_UP;
        xpos--;
        ypos--;
    }

    if (currentKeyStates[SDL_SCANCODE_RIGHT] and currentKeyStates[SDL_SCANCODE_DOWN])
    {
        last_direction = animate_type = RUN_RIGHT_DOWN;
        xpos++;
        ypos++;
    }

    if (currentKeyStates[SDL_SCANCODE_LEFT] and currentKeyStates[SDL_SCANCODE_DOWN])
    {
        last_direction = animate_type = RUN_LEFT_DOWN;
        xpos--;
        ypos++;
    }

    if (!currentKeyStates[SDL_SCANCODE_RIGHT] && !currentKeyStates[SDL_SCANCODE_LEFT] && !currentKeyStates[SDL_SCANCODE_DOWN] && !currentKeyStates[SDL_SCANCODE_UP])
    {
        animate_type = IDLE;
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
    switch (animate_type)
    {
    case IDLE:

        switch (last_direction)
        {
        case RUN_RIGHT:
            SDL_RenderCopy(GameObject::renderer, objTexture, &srcRect, &descRect);
            break;

        case RUN_LEFT:
            SDL_RenderCopyEx(GameObject::renderer, objTexture, &srcRect, &descRect, 0, NULL, SDL_FLIP_HORIZONTAL);
            break;

        case RUN_UP:
            SDL_RenderCopy(GameObject::renderer, objTexture, &srcRect, &descRect);
            break;

        case RUN_DOWN:
            SDL_RenderCopy(GameObject::renderer, objTexture, &srcRect, &descRect);
            break;

        case RUN_LEFT_DOWN:
            SDL_RenderCopyEx(GameObject::renderer, objTexture, &srcRect, &descRect, 0, NULL, SDL_FLIP_HORIZONTAL);
            break;

        case RUN_RIGHT_DOWN:
            SDL_RenderCopy(GameObject::renderer, objTexture, &srcRect, &descRect);
            break;

        case RUN_LEFT_UP:
            SDL_RenderCopyEx(GameObject::renderer, objTexture, &srcRect, &descRect, 0, NULL, SDL_FLIP_HORIZONTAL);
            break;

        case RUN_RIGHT_UP:
            SDL_RenderCopy(GameObject::renderer, objTexture, &srcRect, &descRect);
            break;
        }
    }
}