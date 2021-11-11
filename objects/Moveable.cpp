//
// Created by dima on 12.11.21.
//

#include "Moveable.h"

void Moveable::moveLeft(int pixels, int limit) {
    xAxis = (xAxis - pixels) >= 0 ? xAxis - pixels : limit - width;
}

void Moveable::moveRight(int pixels, int limit) {
    xAxis = (xAxis + pixels) < limit - width ? xAxis + pixels : 0;
}

void Moveable::moveUp(int pixels, int limit) {
    yAxis = (yAxis - pixels) >= 0 ? yAxis - pixels : limit - height;
}

void Moveable::moveDown(int pixels, int limit) {
    yAxis = (yAxis + pixels) < limit - height ? yAxis + pixels : 0;
}