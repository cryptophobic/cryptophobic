//
// Created by dima on 08.11.21.
//

#include "Square.h"
#include <iostream>

Square::Square(int x, int y, int w, int h) : xAxis{x}, yAxis{y}, width{w}, height{h} {}

void Square::moveLeft(int pixels, int limit) {
    xAxis = (xAxis - pixels) >= 0 ? xAxis - pixels : limit - width;
}

void Square::moveRight(int pixels, int limit) {
    xAxis = (xAxis + pixels) < limit - width ? xAxis + pixels : 0;
}

void Square::moveUp(int pixels, int limit) {
    yAxis = (yAxis - pixels) >= 0 ? yAxis - pixels : limit - height;
}

void Square::moveDown(int pixels, int limit) {
    yAxis = (yAxis + pixels) < limit - height ? yAxis + pixels : 0;
}
