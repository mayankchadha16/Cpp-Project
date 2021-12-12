#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Map.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

Player *player;
GameObject *enemy;
GameObject *background;
Map* map;
Game::Game() {}
void Game::init(const char *title, int x, int y, int width, int height, bool fullscreen)
{
    windowWidth = width;
    windowHeight = height;
    int flags = 0;
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystem Initialised\n";

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if (window)
            cout << "Window Created\n";
        else {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created\n";
        }
        else {
            cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
        }
        isRunning = true;
    }
    else
        isRunning = false;
    TextureManager::setRenderer(renderer); // sarthak
    // background = new GameObject("NewMap.png", renderer, 0, 0, windowWidth, windowHeight, 1, 1, 1); // last two args by sarthak
    enemy = new GameObject("Badass.png", 720, 295, 50, 50, 1, 1, 1); // last two args by sarthak
    player = new Player("Character1SpritesWalking.png", 400, 320, 44, 66, 24, 4, 6); // last two args by sarthak

    map = new Map("NewMap.png", 208, 256, windowWidth, windowHeight, 1, 1, 1);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_KEYDOWN:
        if(keyState[SDL_SCANCODE_ESCAPE] != 0)
            isRunning = false;
        else
            handleKeyDownEvents();
        break;

    default:
        break;
    }
}

void Game::handleKeyDownEvents() {

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if(keyState[SDL_SCANCODE_LEFT]) {
        pair<int, int> flags = player->getFlags();
        player->setFlipFlag(true);
        player->setRowControl(1, flags.second);
        map->updatePX(-1);
    }
    
    if(keyState[SDL_SCANCODE_RIGHT]) {
        pair<int, int> flags = player->getFlags();
        player->setFlipFlag(false);
        player->setRowControl(1, flags.second);
        map->updatePX(1);
    }

    if(keyState[SDL_SCANCODE_UP]) {
        pair<int, int> flags = player->getFlags();
        player->setRowControl(flags.first, 1);
        map->updatePY(-1);
    }
    
    if(keyState[SDL_SCANCODE_DOWN]) {
        pair<int, int> flags = player->getFlags();
        player->setRowControl(flags.first, 0);
        map->updatePY(1);
    }

    if (!keyState[SDL_SCANCODE_RIGHT] && !keyState[SDL_SCANCODE_LEFT] && !keyState[SDL_SCANCODE_DOWN] && !keyState[SDL_SCANCODE_UP])
    {
        player->setRowControl(0, 0);
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->Render();
    enemy->Render();
    player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_QUIT;
    cout << "Game Cleaned\n";
}

void Game::update()
{
    player->update();
    map->update();
    enemy->update();
}