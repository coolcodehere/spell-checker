// file to implement a binary search tree of Entry objects

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "ArrayList.h"
using namespace std;

class Dictionary{
private:
    ArrayList<string> *words;
    bool *isOccupied;

public:

    Dictionary();
    ~Dictionary();
    Dictionary(const Dictionary& other);
    Dictionary& operator=(const Dictionary& other);
    

    void addEntry(string anEntry);
    // Preconditions: anEntry has a key not already in the dictionary
    // Postconditions: anEntry has been added to the dictionary

    bool findEntry(string key);
    // Postconditions: if key is found in the dictionary, returns true 
    //   and anEntry is the entry with key; otherwise returns false

    void printSorted(ostream& outStream);
    // Postconditions: has printed contents of the dictionary in order

private:
    long hash(const string &key, long tableSize);
    
    // Finds new indicies for elements.
    // Assumes the array size has already been increased.
    void rehash();
};

#endif


