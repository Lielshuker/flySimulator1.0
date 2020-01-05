//
// Created by user on 1/1/20.
//

#include "IfCommand.h"
int IfCommand::execute(int i, vector<string> stringToPrint) {
    cout <<"left in  if " << stringToPrint[i+1] << endl;
    cout <<"right in  if " << stringToPrint[i+3] << endl;

    int j, start = 0, end = 0;
    Interpreter *rightSide = new Interpreter();
    Interpreter *leftSide = new Interpreter();
    leftSide->enterMap();
    double left, right;
    while (stringToPrint[i] != "{") {
        start++;
        i++;
    }
    end = start;
    while (stringToPrint[i] != "}") {
        end++;
        i++;
    }
    try {
        Expression *expressionRight = rightSide->interpret(stringToPrint[i + 1]);
        Expression *expressionLeft = leftSide->interpret(stringToPrint[i + 3]);

    } catch (...) {
        cout << "error in calculate string" << endl;
    }
    Singleton *singleton = Singleton::getInstance();
    bool enterToIf = false;
    //if(stringToPrint[i+1] == "(") {
    //Interpreter right;
    if (stringToPrint[i + 3] == "=") { // <= / >=
        if (stringToPrint[i + 2] == "<") {
            if (left <= right) {
                return start;
            } else {
                return end;
            }
        }
        if (stringToPrint[i + 3] == ">") {
            if (left >= right) {
                return start;
            } else {
                return end;
            }
        }
    }
    if (stringToPrint[i + 3] == "<") {
        if (left < right) {
            return start;
        } else {
            return end;
        }
    }
    if (stringToPrint[i + 3] == ">") {
        if (left > right) {
            return start;
        } else {
            return end;
        }
    }
    if (stringToPrint[i + 3] == "=") {
        if (stringToPrint[i + 2] == "!") {
            if (left != right) {
                return start;
            } else {
                return end;
            }
        }
        if (stringToPrint[i + 2] == "==") {
            if (left == right) {
                return start;
            } else {
                return end;
            }
        }
    }
}
