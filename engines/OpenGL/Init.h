//
// Created by dima on 23.11.19.
//

#ifndef CRYPTOPHOBIC_INIT_H
#define CRYPTOPHOBIC_INIT_H


class Init {
    static void initializeGlutCallbacks();
    static void renderSceneCB();

public:
    static void start(int argc, char* argv[]);
};


#endif //CRYPTOPHOBIC_INIT_H
