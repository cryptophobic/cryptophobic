//
// Created by dima on 12.11.21.
//

#ifndef SDL_PROJECT_STATE_H
#define SDL_PROJECT_STATE_H

#include "../objects/Object.h"
#include <vector>
#include <string>

class State {
public:
    unsigned putObject(Object*);
    Object* getObject(unsigned objectId);
    std::vector<Object*>* getObjects();
    std::string getObjectsSerialized();

private:
    std::vector<Object*> objects;
};

#endif //SDL_PROJECT_STATE_H
