//
// Created by dima on 11.11.21.
//

#include "../render/SDL/Render.h"
#include "../objects/Square.h"
#include "../events/Keys.h"
#include "../timer/LTimer.h"
#include "Init.h"

void Init::init() {
    Render renderer{Render::DEFAULT_SCREEN_WIDTH, Render::DEFAULT_SCREEN_HEIGHT};
    Square square {0, 0, 40, 40};
    Keys keysHandler;
    int speed = 1;

    LTimer capTimer;

    LTimer squareTimer;

    capTimer.start();
    squareTimer.start();

    //While application is running
    while (true) {
        //Handle events on queue
        auto result = keysHandler.getKey();
        if (result == Keys::QUIT) {
            break;
        }
        if (squareTimer.getTicks() >= SQUARE_SPEED) {
            squareTimer.start();
            if (result & Keys::LEFT) {
                square.moveLeft(speed, renderer.getScreenWidth());
            }
            if (result & Keys::RIGHT) {
                square.moveRight(speed, renderer.getScreenWidth());
            }
            if (result & Keys::UP) {
                square.moveUp(speed, renderer.getScreenHeight());
            }
            if (result & Keys::DOWN) {
                square.moveDown(speed, renderer.getScreenHeight());
            }
        }
        //If frame finished early
        if (capTimer.getTicks() >= SCREEN_TICK_PER_FRAME) {
            capTimer.start();
            renderer.renderSquare(&square);
        }
    }
}
