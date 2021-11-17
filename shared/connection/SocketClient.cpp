//
// Created by dima on 14.11.21.
//

#include "SocketClient.h"

#include <utility>
#include <netinet/in.h>
#include <stdexcept>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

//https://www.geeksforgeeks.org/socket-programming-cc/
//#include <stdio.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <unistd.h>
//#include <string.h>
//#define PORT 8080
//
//int main(int argc, char const *argv[])
//{
//    int sock = 0, valread;
//    struct sockaddr_in serv_addr;
//    char *hello = "Hello from client";
//    char buffer[1024] = {0};
//    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
//    {
//        printf("\n Socket creation error \n");
//        return -1;
//    }
//
//    serv_addr.sin_family = AF_INET;
//    serv_addr.sin_port = htons(PORT);
//
//    // Convert IPv4 and IPv6 addresses from text to binary form
//    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
//    {
//        printf("\nInvalid address/ Address not supported \n");
//        return -1;
//    }
//
//    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
//    {
//        printf("\nConnection Failed \n");
//        return -1;
//    }
//    send(sock , hello , strlen(hello) , 0 );
//    printf("Hello message sent\n");
//    valread = read( sock , buffer, 1024);
//    printf("%s\n",buffer );
//    return 0;
//}
SocketClient::SocketClient(int port, std::string ipAddress) {
    this->port = port;
    this->ipAddress = std::move(ipAddress);
}

void SocketClient::connect() {
    if (connection > 0 && socketId > 0) {
        return;
    }
    sockaddr_in socketAddressStructure{};
    socketId = socket(AF_INET, SOCK_STREAM, 0);
    if (socketId < 0) {
        throw std::runtime_error(std::string("Failed to create socket. errno: ") + std::to_string(errno));
    }

    socketAddressStructure.sin_family = AF_INET;
    socketAddressStructure.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ipAddress.c_str(), &socketAddressStructure.sin_addr)<=0) {
        throw std::runtime_error("Invalid address/ Address not supported");
    }

    if (::connect(socketId, (struct sockaddr *)&socketAddressStructure, sizeof(socketAddressStructure)) < 0){
        throw std::runtime_error("Connection Failed");
    }
}

void SocketClient::write(const std::string &message) {
    send(socketId , message.c_str() , strlen(message.c_str()) , 0 );
}

std::string SocketClient::read() {
    char buffer[8192] = {0};
    ::read(socketId ,buffer, 8192);

    return std::string(buffer);
}
