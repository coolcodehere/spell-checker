#include <iostream>
#include <fstream>
#include <vector>

#include "Dictionary.h"

using namespace std;

// Adds words from provided file to a dictionary
void buildDict(Dictionary &d, string filename) {
    fstream in;
    in.open(filename);
    string buf;

    while(getline(in, buf)) {
        if (!d.findEntry(buf)) {
            d.addEntry(buf);
        }
    }

    in.close();
}


// C++ doens't have a split fucntion for some reason so I made this.
void split(vector<string> &vect, string str) {
    string temp = "";

    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str[i]) && temp != "") {
            vect.push_back(temp);
            temp = "";
        } else if (isalpha(str[i])) {
            temp += tolower(str.at(i));
        }
    }
}


// Gets a vector of words from a provided file.
void getWordVector(vector<string> &v, string filename) {
    fstream in;
    in.open(filename);
    string buf;

    while(getline(in, buf)) {
        split(v, buf);
    }

    in.close();
}


int main(int narg, char** args) {
    printf("Hello World\n");

    Dictionary dict;
    vector<string> words;

    buildDict(dict, "dict.txt");
    buildDict(dict, "mydict.txt");

    getWordVector(words, "test1.txt");

    int mspell = 0;

    for (int i = 0; i < words.size(); i++) {
        if (!dict.findEntry(words.at(i))) {
            mspell++;
        }
    }

    cout << mspell << endl;
}