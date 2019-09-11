//
// Created by Austin on 3/26/2019.
//


#include "Song.h"
#include <time.h>

using namespace std;

Song::Song()
{
    artist = "";
    title = "";
    size = 0;
}

Song::Song(string _artist, string _title, int _size)
{
    artist = _artist;
    title = _title;
    size = _size;
}

void Song:: setartist(string art)
{
    artist = art;
}

string Song:: getartist()
{
    return artist;
}

void Song:: settitle(string tit)
{
    title = tit;
}

string Song:: gettitle()
{
    return title;
}

void Song:: setsize(int siz)
{
    size = siz;
}

int Song:: getsize()
{
    return size;
}

bool Song::operator>(Song const &rhs)
//greater means it should be lower on the list
{
    string artist1 = artist;
    string artist2 = rhs.artist;

    if(artist1.compare(artist2) < 0){

        return false;

    }
    else if (artist1.compare(artist2) > 0){

        return true;
    }
    else {

        string song1 = title;
        string song2 = rhs.title;

        if(song1.compare(song2) < 0){

            return false;

        }
        else if (song1.compare(song2) > 0){

            return true;
        }
        else {

            return (size < rhs.size);

        }

    }

}



bool Song::operator<(Song const &rhs) {

    string artist1 = artist;
    string artist2 = rhs.artist;

    if(artist1.compare(artist2) < 0){

        return true;

    }
    else if (artist1.compare(artist2) > 0){

        return false;
    }
    else {

        string song1 = title;
        string song2 = rhs.title;

        if(song1.compare(song2) < 0){

            return true;

        }
        else if (song1.compare(song2) > 0){

            return false;
        }
        else {

            return (size < rhs.size);

        }

    }

}



bool Song::operator==(Song const &rhs)

{

    if(artist != rhs.artist){

        return false;

    }

    if(title != rhs.title){

        return false;

    }

    if(size != rhs.size){

        return false;

    }else{

        return true;

    }

}

