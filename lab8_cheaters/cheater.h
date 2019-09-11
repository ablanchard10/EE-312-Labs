//
// Created by Austin on 5/1/2019.
//
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <sstream>
#include <fstream>

#ifndef LAB8_CHEATERS_CHEATER_H
#define LAB8_CHEATERS_CHEATER_H

#endif //LAB8_CHEATERS_CHEATER_H

using namespace std;

class Hash
{
private:
    static const int n = 5;                                  //SIZE OF CHUNKS
    struct HashNode{
        int fileIndex;
        HashNode *next;
    };

public:

    Hash();

    static queue<string> chunks;
    static void populatechunks(string line, string word, stringstream iss);
    static int hashFunction(queue<string> chunk);
};