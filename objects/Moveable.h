//
// Created by dima on 12.11.21.
//

#ifndef SDL_PROJECT_MOVEABLE_H
#define SDL_PROJECT_MOVEABLE_H


#include "Object.h"

class Moveable : public Object {
    using Object :: Object;
public:
    void moveLeft(int pixels, int limit);
    void moveRight(int pixels, int limit);
    void moveUp(int pixels, int limit);
    void moveDown(int pixels, int limit);
};


#endif //SDL_PROJECT_MOVEABLE_H
