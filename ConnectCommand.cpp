//
// Created by user on 1/1/20.
//

#include "ConnectCommand.h"
void startTheClient(string ip, int port) {
    Client client(ip,port);
    client.main();
}
int ConnectCommand::execute(int i, vector<string> arrCommand) {
    Interpreter *portInter = new Interpreter();
    portInter->enterMap();
    Expression *portExp = portInter->interpret(arrCommand[i+2]);
    ip = arrCommand[i + 1];
    try {
        this->port = portExp->calculate();
        startTheClient(this->ip, this->port);
    }
    catch (...) {
        throw "ERROR WHILE interpeter at connect command";
    }
    return 2;
}