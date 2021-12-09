#pragma once

#include <SDL2/SDL.h>
#include "Player.h"

class SDLEventManager {
private:
    /* data */
public:
    bool HandleEvents(Player*);
    bool KeyboardEventHandler(Player*);
};
