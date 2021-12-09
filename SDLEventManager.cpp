#include "SDLEventManager.h"
#include "Player.h"

bool SDLEventManager::HandleEvents(Player* player) {
    bool isRunning = true;

    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_KEYDOWN:
        KeyboardEventHandler(player);
        break;
    
    default:
        break;
    }

    return isRunning;
}

bool SDLEventManager::KeyboardEventHandler(Player* player) {
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if(keyState[SDL_SCANCODE_ESCAPE]) {
        return false;
    }
    else {
        player->Keyboard(keyState);
    }
}