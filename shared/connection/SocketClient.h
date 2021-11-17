//
// Created by dima on 14.11.21.
//

#ifndef SDL_PROJECT_SOCKETCLIENT_H
#define SDL_PROJECT_SOCKETCLIENT_H

#include <string>

class SocketClient {
public:
    SocketClient(int port, std::string ipAddress);
    ~SocketClient();
    std::string read();
    void write(const std::string&);
    void connect();

private:
    unsigned port;
    std::string ipAddress;
    int socketId = 0;
    int connection = 0;
};


#endif //SDL_PROJECT_SOCKETCLIENT_H
