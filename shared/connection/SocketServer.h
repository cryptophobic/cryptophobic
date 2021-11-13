//
// Created by dima on 13.11.21.
//

#ifndef SDL_PROJECT_SOCKETSERVER_H
#define SDL_PROJECT_SOCKETSERVER_H

class SocketServer {
public:
    SocketServer(int);
    ~SocketServer();
private:
    unsigned port = 9990;
    int socketId;
    int connection;
    void connect();
    std::string read();
    void write(const std::string&);
};


#endif //SDL_PROJECT_SOCKETSERVER_H
