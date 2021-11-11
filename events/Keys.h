//
// Created by dima on 09.11.21.
//

#ifndef SDL_PROJECT_KEYS_H
#define SDL_PROJECT_KEYS_H

class Keys {
public:
    static const auto QUIT = 16;
    static const auto LEFT = 1;
    static const auto RIGHT = 2;
    static const auto UP = 4;
    static const auto DOWN = 8;
    static const auto PASS = 0;

    unsigned getKey();

private:
    int bitMap = Keys::PASS;
};


#endif //SDL_PROJECT_KEYS_H
