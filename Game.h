#pragma once

#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
#include <iostream>

class Game
{
    protected:
        int cnt = 0;
        bool isRunning;
        SDL_Window *window;
        int windowWidth;
        int windowHeight;

    public:
        SDL_Renderer *renderer;
        Game();
        ~Game();

        void init(const char *title, int x, int y, int width, int height, bool fullscreen);
        void handleEvents();
        void handleKeyDownEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }
};
