//
// Created by dima on 08.11.21.
//

#ifndef SDL_PROJECT_LTIMER_H
#define SDL_PROJECT_LTIMER_H

#include <SDL2/SDL.h>

class LTimer {
public:
    //Initializes variables
    LTimer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    Uint32 getTicks() const;

    //Checks the status of the timer
    bool isStarted() const;
    bool isPaused() const;

private:
    //The clock time when the timer started
    Uint32 mStartTicks;

    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
};


#endif //SDL_PROJECT_LTIMER_H
