//
// Created by dima on 13.11.21.
//

#include <bits/socket.h>
#include <sys/socket.h>
#include <stdexcept>
#include <netinet/in.h>
#include <unistd.h> // For read
#include "SocketServer.h"

void SocketServer::connect() {
    socketId = socket(AF_INET, SOCK_STREAM, 0);
    if (socketId == -1) {
        throw std::runtime_error(std::string("Failed to create socket. errno: ") + std::to_string(errno));
    }

    int opt = 1;
    if (setsockopt(socketId, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        throw std::runtime_error(std::string("Failed to set socket options. Errno: ") + std::to_string(errno));
    }

    // Listen to port 9999 on any address
    sockaddr_in socketAddressStructure{};
    socketAddressStructure.sin_family = AF_INET;
    socketAddressStructure.sin_addr.s_addr = INADDR_ANY;
    socketAddressStructure.sin_port = htons(port); // htons is necessary to convert a number to
    // network byte order
    if (bind(socketId, (struct sockaddr*)&socketAddressStructure, sizeof(socketAddressStructure)) < 0) {
        throw std::runtime_error(std::string("Failed to bind to port ") + std::to_string(port) +". errno: " + std::to_string(errno));
    }

    // Start listening. Hold at most 10 connections in the queue
    if (listen(socketId, 1) < 0) {
        throw std::runtime_error(std::string("Failed to listen on socket. errno: ") + std::to_string(errno));
    }

    // Grab a connection from the queue
    auto addressSize = sizeof(socketAddressStructure);
    connection = accept(socketId, (struct sockaddr*)&socketAddressStructure, (socklen_t*)&addressSize);
    if (connection < 0) {
        throw std::runtime_error(std::string("Failed to grab connection. errno: ") + std::to_string(errno));
    }
}

SocketServer::SocketServer(int portAlterator) {
    port += portAlterator;
}

SocketServer::~SocketServer() {
    close(connection);
    close(socketId);
}

std::string SocketServer::read() {
    char buffer[100];
    auto bytesRead = ::read(connection, buffer, 100);
    //std::cout << "The message was: " << buffer << " bytes read " << bytesRead << std::endl;

    return std::string {buffer};
}

void SocketServer::write(const std::string& response) {
    send(connection, response.c_str(), response.size(), 0);
}
