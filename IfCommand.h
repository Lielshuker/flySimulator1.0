//
// Created by user on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_IFCOMMAND_H
#define FLYSIMULATOR1_0_IFCOMMAND_H

#include "Command.h"
class IfCommand : public Command{
public:
    virtual int execute(int i, vector<string> stringToPrint);
};


#endif //FLYSIMULATOR1_0_IFCOMMAND_H
