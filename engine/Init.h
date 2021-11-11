//
// Created by dima on 11.11.21.
//

#ifndef SDL_PROJECT_INIT_H
#define SDL_PROJECT_INIT_H


const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

const int SQUARE_SPEED = 1000 / 500;

class Init {
public:
    static void init();
};


#endif //SDL_PROJECT_INIT_H
