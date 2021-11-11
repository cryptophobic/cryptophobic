//
// Created by dima on 08.11.21.
//

#include "Render.h"
#include <SDL2/SDL.h>
#include <stdexcept>

Render::~Render() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;
    //Quit SDL subsystems
    SDL_Quit();
}

void Render::init() {

    if (initialized) {
        return;
    }

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(std::string("SDL could not initialize! SDL Error: ") + SDL_GetError());
    }
    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        throw std::runtime_error("Warning: Linear texture filtering not enabled!");
    }

    //Create window
    window = SDL_CreateWindow("Murka Window",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screenWidth,
                              screenHeight,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        throw std::runtime_error(std::string("Window could not be created! SDL Error: ") + SDL_GetError());
    } else {
        //Create renderer for window
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            throw std::runtime_error(std::string("Renderer could not be created! SDL Error: ") + SDL_GetError());
        } else {
            //Initialize renderer color
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }
    initialized = true;
}

void Render::renderSquare(Square *square) {
    init();
    //Clear screen
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    //Render red filled quad
    SDL_Rect fillRect = {square->xAxis, square->yAxis, square->width, square->height};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);

    //Update screen
    SDL_RenderPresent(renderer);
}

int Render::getScreenWidth() const {
    return screenWidth;
}

int Render::getScreenHeight() const {
    return screenHeight;
}

Render::Render(int w, int h) : screenWidth {w}, screenHeight {h} {}
