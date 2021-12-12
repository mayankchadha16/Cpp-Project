#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

// last two args by sarthak
Player::Player(const char *texturesheet, int x, int y, int w, int h, int parts, int rows, int cols)
:GameObject(texturesheet, x, y, w, h, parts, rows, cols) {}

void Player::update()
{
    // updates column in every frame
    colControl = (colControl == (animationControl*6 - 1) ? 0 : colControl + 1);
    colNo = colControl/animationControl;
    rowNo = 2*rowUpFlag + rowLeftFlag;
    // sarthak starts
    updateDestRect();
    Texture->makeSourceRectangle(rowNo, colNo);
    // sarthak ends
}

// set flipflag
void Player::setFlipFlag(bool flag) {
    flipFlag = flag;
}

// get flipFlag
bool Player::getFlipFlag() {
    return flipFlag;
}

// set rowControl (left, up)
void Player::setRowControl(int leftFlag, int upFlag) {
    rowLeftFlag = leftFlag;
    rowUpFlag = upFlag;
}

// get flags
pair<int, int> Player::getFlags() {
    return make_pair(rowLeftFlag, rowUpFlag);
}

// void Player::Keyboard()
// {
//     rowNo = 2*rowUpFlag + rowLeftFlag;
// }

void Player::Render()
{
    GameObject::Render(flipFlag);
}

// get coords
pair<int, int> Player::GetCoords() {
    return (make_pair(xpos, ypos));
}