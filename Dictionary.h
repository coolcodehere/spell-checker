// file to implement a binary search tree of Entry objects

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>

using namespace std;


class Dictionary{
    private:
        string *arr;
        int capacity;
        int size;

    public:

        Dictionary();
        // Creates an empty dictionary;

        Dictionary(const Dictionary& orig);
        // Copy constructor

        virtual ~Dictionary();
        // Destructor

        Dictionary& operator=(const Dictionary& orig);
        // assignment operator
        

        void addEntry(string anEntry);
        // Preconditions: anEntry has a key not already in the dictionary
        // Postconditions: anEntry has been added to the dictionary

        bool findEntry(string key);
        // Postconditions: if key is found in the dictionary, returns true 
        //   and anEntry is the entry with key; otherwise returns false

        void printSorted(ostream& outStream);
        // Postconditions: has printed contents of the dictionary in order

        void test();
 private:
        
        void copyDict(const Dictionary& orig);
        // copies the contents of orig to this dictionary

        void deleteDict();
        // properly frees all memory occupied by this Dictionary

        // gets the index for key
        int hash(const string &key, int tableSize);

        // resizes the array to double+nextprime
        int resize(string *arr, int tableSize);

        // Returns the next prime number size
        long getNextSize(int size);
};

#endif


