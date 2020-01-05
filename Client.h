//
// Created by user on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_CLIENT_H
#define FLYSIMULATOR1_0_CLIENT_H
// Client side C/C++ program to demonstrate Socket programming
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
#include "Singleton.h"
using namespace std;

class Client {
    int _port;
    string _ip;
public:
    Client(string ip, int port);
    int main();
};


#endif //FLYSIMULATOR1_0_CLIENT_H
