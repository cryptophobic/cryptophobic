//
// Created by dima on 09.11.21.
//

#include <SDL2/SDL.h>
#include "Keys.h"

unsigned Keys::getKey() {
    //Event handler
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        //User requests quit
        if (e.type == SDL_QUIT) {
            return QUIT;
        } else if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
            //Select surfaces based on key press
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    return QUIT;
                case SDLK_UP:
                    bitMap |= UP;
                    break;
                case SDLK_DOWN:
                    bitMap |= DOWN;
                    break;
                case SDLK_LEFT:
                    bitMap |= LEFT;
                    break;
                case SDLK_RIGHT:
                    bitMap |= RIGHT;
                    break;
            }
        } else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    bitMap = (bitMap & UP) == UP ? bitMap ^ UP : bitMap;
                    break;
                case SDLK_DOWN:
                    bitMap = (bitMap & DOWN) == DOWN ? bitMap ^ DOWN : bitMap;
                    break;
                case SDLK_LEFT:
                    bitMap = (bitMap & LEFT) == LEFT ? bitMap ^ LEFT : bitMap;
                    break;
                case SDLK_RIGHT:
                    bitMap = (bitMap & RIGHT) == RIGHT ? bitMap ^ RIGHT : bitMap;
                    break;
            }
        }
    }

    return bitMap;
}
