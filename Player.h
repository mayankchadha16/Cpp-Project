#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
#include <utility>
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

// sarthak starts
enum idlePictureNumber {
    IDLE_FRONT_STRAIGHT_1,
    IDLE_FRONT_STRAIGHT_2,
    IDLE_FRONT_STRAIGHT_3,
    IDLE_FRONT_STRAIGHT_4,
    IDLE_FRONT_RIGHT_1,
    IDLE_FRONT_RIGHT_2,
    IDLE_FRONT_RIGHT_3,
    IDLE_FRONT_RIGHT_4,
    IDLE_BACK_STRAIGHT_1,
    IDLE_BACK_STRAIGHT_2,
    IDLE_BACK_STRAIGHT_3,
    IDLE_BACK_STRAIGHT_4,
    IDLE_BACK_RIGHT_1,
    IDLE_BACK_RIGHT_2,
    IDLE_BACK_RIGHT_3,
    IDLE_BACK_RIGHT_4
};

enum walkPictureNumber {
    WALK_FRONT_STRAIGHT_1,
    WALK_FRONT_STRAIGHT_2,
    WALK_FRONT_STRAIGHT_3,
    WALK_FRONT_STRAIGHT_4,
    WALK_FRONT_STRAIGHT_5,
    WALK_FRONT_STRAIGHT_6,
    WALK_FRONT_RIGHT_1,
    WALK_FRONT_RIGHT_2,
    WALK_FRONT_RIGHT_3,
    WALK_FRONT_RIGHT_4,
    WALK_FRONT_RIGHT_5,
    WALK_FRONT_RIGHT_6,
    WALK_BACK_STRAIGHT_1,
    WALK_BACK_STRAIGHT_2,
    WALK_BACK_STRAIGHT_3,
    WALK_BACK_STRAIGHT_4,
    WALK_BACK_STRAIGHT_5,
    WALK_BACK_STRAIGHT_6,
    WALK_BACK_RIGHT_1,
    WALK_BACK_RIGHT_2,
    WALK_BACK_RIGHT_3,
    WALK_BACK_RIGHT_4,
    WALK_BACK_RIGHT_5,
    WALK_BACK_RIGHT_6,
};
// sarthak ends

class Player : public GameObject
{
public:
    Player(const char *, int x, int y, int w, int h, int parts, int rows, int cols); // last two args by sarthak
    ~Player();
    void update();
    void Render();
    // get coordinates
    pair<int, int> GetCoords();
    // set flipflag
    void setFlipFlag(bool);
    // get flipFlag
    bool getFlipFlag();
    // set rowControl
    void setRowControl(int leftFlag, int upFlag);
    // return flags
    pair<int, int> getFlags();

private:
    bool flipFlag = false;
    int stepSize = 3;
    // column number control
    int colControl = 0, colNo = 0, animationControl = 6;
    // row number control
    int rowNo = 0, rowLeftFlag = 0, rowUpFlag = 0;
};