/* utPod_driver.cpp
Demo Driver for the UtPod.

Austin Blanchard
EE 312 3/26/19

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "UtPod.h"

using namespace std;

int main()
{
    string line;
    ifstream myfile("test.txt");

    UtPod t;


    if(myfile.is_open())
    {
        while (getline (myfile,line))
        {
            if (line == "add")
            {
                string artist;
                string title;
                string stringsize;
                getline (myfile, artist);
                getline (myfile, title);
                getline (myfile, stringsize);
                int size = atoi(stringsize.c_str());
                Song s1 (artist, title, size);
                int result = t.addSong(s1);
                cout << "add result = " << result << endl;
            }

            if (line == "show")
            {
                t.showSongList();
            }

            if (line == "remove")
            {
                string artist;
                string title;
                string stringsize;
                getline (myfile, artist);
                getline (myfile, title);
                getline (myfile, stringsize);
                int size = atoi(stringsize.c_str());
                Song s1 (artist, title, size);
                int result = t.removeSong(s1);
                cout << "remove result = " << result << endl;
            }

            if (line == "shuffle")
            {
                t.shuffle();
            }
            if (line == "sort")
            {
                t.sortSongList();
            }
            if(line == "total")
            {
                int memor = t.getTotalMemory();
                cout << memor << endl;
            }
            if(line == "clear")
            {
                t.clearMemory();
            }
            if(line == "remaining")
            {
                int remaining = t.getRemainingMemory();
                cout << remaining << endl;
            }


        }
    }




/*




    Song s1("Beatles", "Hey Jude1", 4);
    Song s2("Beatles", "Hey Jude2", 5);
    Song s3("Beatles", "Hey Jude3", 6);
    Song s4("Beatles", "Hey Jude4", 7);
    Song s5("Beatles", "Hey Jude5", 241);

    int result = t.addSong(s1);

    result = t.addSong(s2);

    result = t.addSong(s3);
    result = t.addSong(s4);
    result = t.addSong(s5);

    t.showSongList();
    cout << "list^" <<endl;
    t.shuffle();

    t.showSongList();
    cout << "shuffled^" << endl;
    t.removeSong(s3);
    t.showSongList();
    cout << "no size 6^" << endl;
    t.sortSongList();
    t.showSongList();
    cout << "sorted^" << endl;
*/
    //cout << "result = " << result << endl;

    //t.showSongList();



    //cout << "result = " << result << endl;


    //cout << "result = " << result << endl;

    //t.showSongList();
    //t.sortSongList();
    //t.showSongList();
/*    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    t.showSongList();



    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

*/
}