#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <sstream>
#include <fstream>
#include "cheater.h"

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[])            // main() on clion
{
    string dir = string("sm_doc_set");                   //string("sm_doc_set"); for clion, argv[1] for putty
    vector<string> files = vector<string>();

    getdir(dir, files);
    cout << dir << endl;
    files.erase(files.begin(), files.begin() + 2);        //erase first two lines of 0 . and 1 ..

    for (unsigned int i = 0; i < files.size(); i++) {
        cout << i << files[i] << endl;
    }

    int count = 5;
    queue<string> chunks;

    string line;
    string fname = files[0];

    ifstream myfile("sm_doc_set/abf0704.txt");

    if (myfile.is_open())
    {
        cout << "ITS OPEN" << endl;
        while(getline(myfile, line))               //line has first line of essay
        {
            string chunk;
            stringstream iss(line);
            //now fill up queue with first 5 word sequence
            for(count; count > 0; count--)
            {
                iss >> chunk;
                chunks.push(chunk);
                cout << "CHUNK IS " << chunk << endl;
            }
            //Hash::populatechunks(line, chunk, iss);

            Hash::hashFunction(chunks);

        }
    }


    return 0;
}