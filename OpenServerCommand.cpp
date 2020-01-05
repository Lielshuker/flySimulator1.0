//
// Created by user on 1/1/20.
//

#include "OpenServerCommand.h"
void startServer(int portListen) {
    Server server(portListen);
    server.main();
}
int OpenServerCommand::execute(int i, vector<string> arrCommand) {
    Interpreter *portInter = new Interpreter();
    portInter->enterMap();
    Expression *portExp = portInter->interpret(arrCommand[i+1]);
    try {
        this->portListen = portExp->calculate();
        startServer(this->portListen);
    }
    catch (...) {
        throw "ERROR WHILE INTERPETER OPERN DATA SERVER";
    }
    return 1;
};
