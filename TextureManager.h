#pragma once

#include "Game.h"
#include <SDL2/SDL.h> //
#include <SDL2/SDL_image.h>
#include <string>   // sarthak
#include <vector>   // sarthak
using namespace std;

class TextureManager
{
    private:
        // sarthak starts
        // texture
        SDL_Texture* texture;

        // stores all the textures
        vector<SDL_Texture*> textureList;

        // dimensions of the whole image
        int TextWidth;
        int TextHeight;

        // dimensions of the source
        int SrcWidth;
        int SrcHeight;

        // image rectangle
        SDL_Rect srcRect;

        // number of partitions of the texture
        int parts;

        // number of rows and cols of the grid of the texture
        int rows, cols;

        // set the image rectangle
        // void setImageRectangle(int x, int y, SDL_Rect* clip);

        // sarthak ends

    public:
        // sarthak start

        // renderer
        static SDL_Renderer* renderer;
        // Constructor
        TextureManager();

        // Destructor
        ~TextureManager();  

        // tries to load the texture and returns if it was successful or not
        bool loadTexture(string fName, int parts, int rows, int cols);

        // make grids out of the texture
        bool makeGrid(int noOfParts, int noOfRows, int noOfCols);

        // make the source rectangle
        bool makeSourceRectangle(int partNumber);

        // destroy the texture
        void destroyTexture();

        // render the texture
        void render(SDL_Rect* dispRect, bool flipFlag = false);

        // set the renderer
        static void setRenderer(SDL_Renderer* rend);
        // sarthak ends
};