#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

enum animation_type
{
    IDLE,
    RUN_RIGHT,
    RUN_LEFT,
    RUN_UP,
    RUN_DOWN,
    RUN_LEFT_UP,
    RUN_LEFT_DOWN,
    RUN_RIGHT_UP,
    RUN_RIGHT_DOWN
};

class Player : public GameObject
{
public:
    Player(const char *, SDL_Renderer *, int, int);
    ~Player();
    void update(int, int);
    void Render();
    void Keyboard();

private:
    int last_direction = RUN_RIGHT;
    int animate_type = -1;
    bool flipFlag = false;
    int stepSize = 3;
};