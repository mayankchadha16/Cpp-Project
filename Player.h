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

// // sarthak starts
// enum idlePictureNumber {
//     FRONT_STRAIGHT_1,
//     FRONT_STRAIGHT_2,
//     FRONT_STRAIGHT_3,
//     FRONT_STRAIGHT_4,
//     FRONT_RIGHT_1,
//     FRONT_RIGHT_2,
//     FRONT_RIGHT_3,
//     FRONT_RIGHT_4,
//     BACK_STRAIGHT_1,
//     BACK_STRAIGHT_2,
//     BACK_STRAIGHT_3,
//     BACK_STRAIGHT_4,
//     BACK_RIGHT_1,
//     BACK_RIGHT_2,
//     BACK_RIGHT_3,
//     BACK_RIGHT_4
// };

// enum walkPictureNumber {
//     FRONT_STRAIGHT_1,
//     FRONT_STRAIGHT_2,
//     FRONT_STRAIGHT_3,
//     FRONT_STRAIGHT_4,
//     FRONT_STRAIGHT_5,
//     FRONT_STRAIGHT_6,
//     FRONT_RIGHT_1,
//     FRONT_RIGHT_2,
//     FRONT_RIGHT_3,
//     FRONT_RIGHT_4,
//     FRONT_RIGHT_5,
//     FRONT_RIGHT_6,
//     BACK_STRAIGHT_1,
//     BACK_STRAIGHT_2,
//     BACK_STRAIGHT_3,
//     BACK_STRAIGHT_4,
//     BACK_STRAIGHT_5,
//     BACK_STRAIGHT_6,
//     BACK_RIGHT_1,
//     BACK_RIGHT_2,
//     BACK_RIGHT_3,
//     BACK_RIGHT_4,
//     BACK_RIGHT_5,
//     BACK_RIGHT_6,
// };
// // sarthak ends

class Player : public GameObject
{
public:
    Player(const char *, SDL_Renderer *, int x, int y, int w, int h, int parts, int rows, int cols); // last two args by sarthak
    ~Player();
    void update();
    void Render();
    void Keyboard();

private:
    int last_direction = RUN_RIGHT;
    int animate_type = -1;
    bool flipFlag = false;
    int stepSize = 3;
};