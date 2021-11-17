//
// Created by dima on 13.11.21.
//

#ifndef SDL_PROJECT_SOCKETSERVER_H
#define SDL_PROJECT_SOCKETSERVER_H

class SocketServer {
public:
    SocketServer(int);
    ~SocketServer();
    std::string read();
    void write(const std::string&);

private:
    unsigned port = 9990;
    int socketId = 0;
    int connection = 0;
    void connect();
};


#endif //SDL_PROJECT_SOCKETSERVER_H
