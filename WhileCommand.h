//
// Created by adi on 1/2/20.
//

#ifndef FLYSIMULATOR1_0_WHILECOMMAND_H
#define FLYSIMULATOR1_0_WHILECOMMAND_H

#include "Command.h"
class WhileCommand : public Command {
public:
    virtual int execute(int i, vector<string> stringToPrint);
    string checkSpace(string str);
};


#endif //FLYSIMULATOR1_0_WHILECOMMAND_H
