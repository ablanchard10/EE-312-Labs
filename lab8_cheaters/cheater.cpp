//
// Created by Austin on 5/1/2019.
//

#include "cheater.h"

using namespace std;

void Hash::populatechunks(string line, string word, stringstream iss) {
    int count = Hash::n;
    for(count; count > 0; count--)
    {
        iss >> word;
        //Hash::chunks.push(word);
        cout << "CHUNK IS " << word << endl;
    }
    //chunks has first 5 words
}

int Hash::hashFunction(queue<string> chunk) {                       //

}

Hash::Hash() {
    table = new HashNode*[TABLE_SIZE];
    numFiles = files.size();
    for (int i = 0; i < TABLE_SIZE; i ++)   {
        table[i] = NULL;
    }
    collisions = new int*[numFiles];
    for (int i = 0; i < numFiles; i ++) {
        collisions[i] = new int[numFiles];
        for (int j = 0; j < numFiles; j ++) {
            collisions[i][j] = 0;
        }
    }
}
