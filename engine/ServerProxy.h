//
// Created by dima on 12.11.21.
//

#ifndef SDL_PROJECT_SERVERPROXY_H
#define SDL_PROJECT_SERVERPROXY_H


#include <string>
#include "State.h"

class ServerProxy {
public:
    ServerProxy(State*);
    void getAndUpdateState();
    void put(std::string);

private:
    State* statePtr;
};


#endif //SDL_PROJECT_SERVERPROXY_H
