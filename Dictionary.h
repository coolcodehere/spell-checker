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
    // v-- Memory Management --v
    Dictionary(int capacity);
    ~Dictionary();
    Dictionary(const Dictionary& other);
    Dictionary& operator=(const Dictionary& other);
    
    // Adds a string to the hash set
    void addEntry(string val);

    // Returns true if value is in the hash set
    bool findEntry(string val);

    // Outputs a list of items to the provied stream
    void printSorted(ostream& outStream);

private:
    // Returns a hash value to use for an index
    int hash(const string &key, int tableSize);

    // Returns the prime after index
    int findFirstEmptyIndex(int index);

    // Redistributes values to the set after it has grown in size.
    void rehash();
};

#endif


