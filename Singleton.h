//
// Created by user on 1/1/20.
//

#ifndef FLYSIMULATOR1_0_SINGLETON_H
#define FLYSIMULATOR1_0_SINGLETON_H

#include <map>
#include <vector>
#include "ex1.h"
#include "hash_map"
#include <mutex>
#include <iostream>
#include <cstring>
using namespace std;
class Singleton {
private:
    /* Here will be the instance stored. */
    static Singleton *instance;
    /* Private constructor to prevent instancing. */

    char **arrFromBufferSmi;
public:
    vector<string> infoFromSim  = {"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};

    mutex mtx;
    /* Static access method. */
    map<string, int> simToNum ;
    map<string, Variable> singerVar;
//    };
    void makeSingelVar(string str, string val);
    map<string, Variable> infoFromSimulator; //= new <char*, Variable()>;
    // map<string, Variable> varToSimulator;
    void parsingXML();
    Singleton();
    void creatingInfoFromSim(string var, string sim);
    // Singleton getInstance();
    static Singleton *getInstance();
    void creatingVarIntoMap(string var, string sim);
    void insertValue(string value, string nameVar);
    vector<string> get();
    void set(vector<string> info);
};


#endif //FLYSIMULATOR1_0_SINGLETON_H
