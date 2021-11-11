#include "render/SDL/Render.h"
#include "objects/Square.h"
#include "events/Keys.h"
#include "timer/LTimer.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

const int SQUARE_SPEED = 1000 / 500;

int main(int argc, char *args[]) {
    Render renderer{Render::DEFAULT_SCREEN_WIDTH, Render::DEFAULT_SCREEN_HEIGHT};
    Square square{0, 0, 40, 40};
    Keys keysHandler;
    int speed = 1;

    LTimer capTimer;
    int countedFrames = 0;

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
    return 0;
}
