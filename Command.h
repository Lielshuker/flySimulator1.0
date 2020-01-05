//
// Created by user on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_COMMAND_H
#define FLYSIMULATOR1_0_COMMAND_H
#include <iostream>
#include <map>
#include "thread"
#include "Client.h"
#include "Server.h"
#include "Singleton.h"
#include <vector>
#include <unistd.h>

using namespace std;
class Command {
public:
    virtual int execute(int i,  vector<string> arrCommand) = 0;
};


#endif //FLYSIMULATOR1_0_COMMAND_H
