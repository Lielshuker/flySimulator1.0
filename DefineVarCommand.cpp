//
// Created by user on 1/1/20.
//

#include "DefineVarCommand.h"
int DefineVarCommand::execute(int i, vector<string> arrCommand) {
    Singleton *s = s->getInstance();
    string temp = arrCommand[i+1];
    temp = arrCommand[i+2];
    if(temp == "<-") {
        s->creatingInfoFromSim(arrCommand[i+1], arrCommand[i+4]);
    }
    else if (temp == "->") {
        s->creatingInfoFromSim(arrCommand[i+1], arrCommand[i+4]);
    }
    else if (temp == "=") {
        cout << "enter = in var = x" << endl;
        s->makeSingelVar(arrCommand[i+1],arrCommand[i+3]);
        return 3;
    }
    return 4;
}