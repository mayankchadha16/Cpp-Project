#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
#include "Game.h"
#include <iostream>
using namespace std;

int main()
{
    // SDL_Init(SDL_INIT_EVERYTHING);//Also can use SDL_INIT_VIDEO
    // SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOWS_SHOWN);//TITLE X Y W H FLAGS
    // SDL_Renderer *renderer = SDL_CreateRenderer(windows,-1,0);//WINDOW INDEX FLAG

    // SDL_SetRenderDrawColor(renderer,0,255,0,255);//RENDERER RED GREEN BLUE ALPHA

    // SDL_RenderClear(renderer);//TO CHANGE COLOUR TO GIVEN NOT BLACK
    // SDL_RenderPresent(renderer);

    // SDL_Delay(10000);
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    long long frameStart;
    int frameTime;
    Game *game = new Game(); //Game*game

    // title, title_xcoord, title_ycoord, screenWidth, screenHeight, fullscreen
    game->init("Maynk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, false);
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay-frameTime);
        }
    }
    game->clean();

    return 0;
}