#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "ArrayList.h"
using namespace std;

class Dictionary{
private:
    int capacity;
    int numVals = 0;

    string *set;
    string *valStore;
    bool *isOccupied;

public:
    Dictionary(int capacity);
    ~Dictionary();
    Dictionary(const Dictionary& other);
    Dictionary& operator=(const Dictionary& other);
    
    void addEntry(string val);
    bool findEntry(string val);
    void printSorted(ostream& outStream);

private:
    int hash(const string &key, int tableSize);
    int findFirstEmptyIndex(int index);
    void rehash();
};

#endif


