//
// Created by user on 1/1/20.
//

#include "lexer.h"



void lexer::readFile(string sFile) {
    int i;
    ifstream fp("fly.txt");
    bool flagNotSplipStart = false;
    bool flagNotSplipEnd = false;
    set<char> unsign= {'(', ')', ',', ' ','\n','\t'};
    char c;
    string str = "";
    bool flagSpace = true;
    bool flagConnect = false;
    while (fp.get(c)) {
        if (c == '"') {
            flagNotSplipStart = !flagNotSplipStart;
        }
        if(flagNotSplipStart && c == '\n') {
            if(str[str.length()-1] == ')') {
                str = str.substr(0, str.length() - 1);
            }
            flagNotSplipStart = false;
        }
        if ((unsign.find(c) == unsign.end()) || (flagNotSplipStart)) {
            if (c != '"' && c != '\\') {
                str = str + c;
                flagSpace = true;
            }
        } else if (flagSpace){
            stringFromFile.push_back(str);
            countArr++;
            if(flagConnect) {
                flagNotSplipStart = true;
                flagConnect = false;
            }
            if (str == "openDataServer" || str == "=" || str == "Sleep" || str == "if" || str == "while"){// || flagConnect) {
                flagNotSplipStart = true;
            }
            if (str == "connectControlClient") {
                flagConnect = true;
            }
            cout << str<<endl;
            str = "";
            flagSpace = false;

        }
        i++;
    }
}

void lexer::mappingoCommand() {
    this->mapCommand.insert(pair<string, Command*>("openDataServer",  new OpenServerCommand()));
    this->mapCommand.insert(pair<string, Command*>("connectControlClient", new ConnectCommand()));
    this->mapCommand.insert(pair<string, Command*>("var", new DefineVarCommand()));
    this->mapCommand.insert(pair<string, Command*>("Print", new PrintCommand()));
    this->mapCommand.insert(pair<string, Command*>("Sleep", new SleepCommand()));
    this->mapCommand.insert(pair<string, Command*>("if", new IfCommand()));
    this->mapCommand.insert(pair<string, Command*>("while", new WhileCommand()));

};
void lexer::parser() {
    int i,temp, countWhileEnd = 0;
    bool whileLoop = false;
    Singleton *singleton = singleton->getInstance();
    for (i = 0; i < countArr; i++) {
        if (whileLoop) {
        //    countWhileEnd++;
            if (stringFromFile[i] == "}") {
                whileLoop = false;
                i = (countWhileEnd - 1);
            }
        }
        if (this->mapCommand.find(stringFromFile[i]) != this->mapCommand.end()){
            Command *c = this->mapCommand[stringFromFile[i]];
            if ( c != NULL) {
                temp = i + c->execute(i, this->stringFromFile);
                if (temp < i) {
                       whileLoop = true;
                    temp = temp + 2;
                    countWhileEnd = temp;
                }
                i = temp;
            }
        }
        string str = stringFromFile[i];
        if ((singleton->infoFromSimulator.find(str) != singleton->infoFromSimulator.end())  || (singleton->singerVar.find(str) != singleton->singerVar.end())) {
            if (stringFromFile[i + 1] == "=") {
                singleton->insertValue(stringFromFile[i + 2], stringFromFile[i]);
            }
        }
    }
};

