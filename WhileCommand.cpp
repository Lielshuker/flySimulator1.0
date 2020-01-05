//
// Created by adi on 1/2/20.
//

#include "WhileCommand.h"
string WhileCommand ::  checkSpace(string str) {
    int i;
    string final = "";
    for(i = 0; i < str.size() ; i++) {
        if (str[i] != ' ') {
            final = final + str[i];
        }
    }
    return final;
}
int WhileCommand::execute(int i, vector<string> stringToPrint) {
    bool spaceStart = false;
    bool spaceEnd = false;
    bool twoOperators = false;
    Singleton *singleton = singleton->getInstance();
//    for(auto e : singleton->infoFromSimulator) {
//        cout << "map: " << "first : " << e.first << " " << "second " << e.second.getValue();
//    }
    set<char> operators { '<','>','!','='};
    int count = i, end = 0, j = 0,temp = i;
    while (stringToPrint[temp] != "}") {
        temp++;
    }
    end = temp - i;

    stringToPrint[i+1] = checkSpace(stringToPrint[i+1]);
    for (j; j < stringToPrint[i+1].size() ; j++) {
    if(operators.find(stringToPrint[i+1][j]) != operators.end()) {
        if (operators.find(stringToPrint[i+1][j+1]) != operators.end()) {
            twoOperators = true;
        }
        break;
    }
}
    string leftString, rightString;
    leftString = stringToPrint[i + 1].substr(0, j);
    if (twoOperators) {
        rightString = stringToPrint[i + 1].substr(j + 2, stringToPrint[i].size() - 1);
    } else {
        rightString = stringToPrint[i + 1].substr(j + 1, stringToPrint[i].size() - 1);
    }
//    cout << "right:" << rightString << " " << "left " << leftString<< endl;
    Interpreter *rightSide = new Interpreter();
    Interpreter *leftSide = new Interpreter();
    leftSide->enterMap();
    Expression *expressionRight = rightSide->interpret(rightString);
    Expression *expressionLeft = leftSide->interpret(leftString);
    double left = expressionLeft->calculate();
    double right = expressionRight->calculate();
        if (stringToPrint[i + 1][j] == '<') {
            if (stringToPrint[i+1][j + 1] == '=') {
                if (left <= right) {
                    return -1;
                }
                return end;
            }
            if (left < right) {
                return -1;
            }
            return end;
        }
        if (stringToPrint[i + 1][j] == '>') {
            if (stringToPrint[i + 1][j+1] == '=') {
                if (left >= right) {
                    return -1;
                }
                return end;
            }
            cout << " befor" << endl;
            if (left >= right) {
                return -1;
            }
            return end;
        }
        if (stringToPrint[i + 1][j+1] == '=') {
            if (stringToPrint[i + 1][j] == '=') {
                if (left == right) {
                    return -1;
                }
                return end;
            }
            if (stringToPrint[i + 1][j] == '!') {
                if (left != right) {
                    return -1;
                }
                return end;
            }
        }
    }
//}

