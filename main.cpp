#include <iostream>
#include <fcntl.h>
#include "lexer.h"
int main() {
    lexer l;
//    Singleton* singleton = singleton->getInstance();
//    singleton->parsingXML();
    l.readFile("fly.txt");
    l.mappingoCommand();
    l.parser();
};