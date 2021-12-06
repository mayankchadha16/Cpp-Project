#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
using namespace std;

Player *player;
GameObject *enemy;
GameObject *background;
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
    background = new GameObject("Background.png", renderer, 0, 0, windowWidth, windowHeight, 1, 1, 1); // last two args by sarthak
    enemy = new GameObject("Badass.png", renderer, 720, 295, 50, 50, 1, 1, 1); // last two args by sarthak
    player = new Player("Character1SpritesIdle.png", renderer, 7, 270, 43, 53, 16, 2, 4); // last two args by sarthak
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    background->Render();
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
    background->update();
    enemy->update();
    player->update();
}