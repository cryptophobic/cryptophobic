//
// Created by dima on 12.11.21.
//

#include "ServerProxy.h"

void client::ServerProxy::getAndUpdateState() {

}

void client::ServerProxy::put(std::string) {
    std::string serialized;
    for (Object *object: *statePtr->getObjects()) {
        serialized += std::to_string(object->xAxis) + ","
                      + std::to_string(object->yAxis) + ","
                      + std::to_string(object->width) + ","
                      + std::to_string(object->height) + "|";
    }
}

client::ServerProxy::ServerProxy(State *newStatePtr) {
    statePtr = newStatePtr;
}
