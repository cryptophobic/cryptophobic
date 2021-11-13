//
// Created by dima on 08.11.21.
//

#ifndef SDL_PROJECT_RENDER_H
#define SDL_PROJECT_RENDER_H

#include <SDL2/SDL.h>
#include "../../../shared/objects/Square.h"

namespace client {
    class Render {

    public:
        Render(int, int);

        ~Render();

        void renderSquare(Square *);

        static const auto DEFAULT_SCREEN_WIDTH = 1024;
        static const auto DEFAULT_SCREEN_HEIGHT = 768;

        [[nodiscard]] int getScreenWidth() const;

        [[nodiscard]] int getScreenHeight() const;

    private:
        SDL_Renderer *renderer = nullptr;
        SDL_Window *window = nullptr;

        int screenWidth = DEFAULT_SCREEN_WIDTH;
        int screenHeight = DEFAULT_SCREEN_HEIGHT;
        bool initialized = false;

        void init();
    };
}

#endif //SDL_PROJECT_RENDER_H
