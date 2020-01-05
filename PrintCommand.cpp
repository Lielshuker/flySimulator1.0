//
// Created by user on 1/1/20.
//


#include "PrintCommand.h"
int PrintCommand::execute(int i, vector<string> stringToPrint) {
    Singleton *singleton = singleton->getInstance();
    if (singleton->infoFromSimulator.find(stringToPrint[i + 1]) != singleton->infoFromSimulator.end()) {
        cout << singleton->infoFromSimulator.find(stringToPrint[i+1])->second.getValue() << endl;
    } else {
        cout << stringToPrint[i + 1] << endl;
    }
    return 1;
}
