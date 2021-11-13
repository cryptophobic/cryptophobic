//
// Created by dima on 12.11.21.
//

#include "State.h"

unsigned client::State::putObject(Object *object) {
    objects.push_back(object);
    return objects.size() - 1;
}

Object *client::State::getObject(unsigned int objectId) {
    return objects[objectId];
}

std::string client::State::getObjectsSerialized() {
    std::string serialized;
    for (Object* object : objects) {
        serialized += std::to_string(object->xAxis) + ","
                + std::to_string(object->yAxis) + ","
                + std::to_string(object->width) + ","
                + std::to_string(object->height) + "|";
    }
    return serialized;
}

std::vector<Object *>* client::State::getObjects() {
    return &objects;
}
