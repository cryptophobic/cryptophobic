//
// Created by dima on 18.11.19.
//

#include <GL/glut.h>
#include <iostream>
#include "Controller.h"

Controller::Controller() = default;

Controller::~Controller() = default;

void Controller::control(int key, int x, int y) {
    switch (key){
        case GLUT_KEY_UP:
        {
            std::cout << "up" << std::endl;
            break;
        }
        case GLUT_KEY_DOWN:
        {
            std::cout << "down" << std::endl;
            break;
        }
        case GLUT_KEY_LEFT:
        {
            std::cout << "left" << std::endl;
            break;
        }
        case GLUT_KEY_RIGHT:
        {
            std::cout << "right" << std::endl;
            break;
        }
    }

}

void Controller::control(unsigned char key, int x, int y) {
    if (key == 'q') {
        std::cout << "bye " << std::endl;
        exit(0);
    }
    std::cout << "fires ordinary " << key << std::endl;
}
