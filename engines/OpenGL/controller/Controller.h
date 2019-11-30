//
// Created by dima on 18.11.19.
//

#ifndef CRYPTOPHOBIC_CONTROLLER_H
#define CRYPTOPHOBIC_CONTROLLER_H


class Controller {

public:
    Controller();
    ~Controller();
    void control(int key, int x, int y);
    void control(unsigned char key, int x, int y);
};


#endif //CRYPTOPHOBIC_CONTROLLER_H
