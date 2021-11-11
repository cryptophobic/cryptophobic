//
// Created by dima on 08.11.21.
//

#ifndef SDL_PROJECT_SQUARE_H
#define SDL_PROJECT_SQUARE_H


class Square {
public:
    Square(int, int, int, int);
    int xAxis = 0;
    int yAxis = 0;
    int width = 0;
    int height = 0;

    void moveLeft(int pixels, int limit);
    void moveRight(int pixels, int limit);
    void moveUp(int pixels, int limit);
    void moveDown(int pixels, int limit);
};

#endif //SDL_PROJECT_SQUARE_H
