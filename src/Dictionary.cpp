#include <algorithm>
#include <iostream>
#include <string>
#include "Dictionary.h"
#include "Primes.h"

Dictionary::Dictionary() {
    const uint capacity = 5;

    words = new ArrayList<string>;
    isOccupied = new bool[capacity];
    
    for (uint i = 0; i < capacity; i++) {
        isOccupied[i] = false;
    }
}

Dictionary::~Dictionary() {
    delete words;
    delete[] isOccupied;
}

Dictionary::Dictionary(const Dictionary& other) {
    words = other.words;
    isOccupied = other.isOccupied;
}


Dictionary& Dictionary::operator=(const Dictionary& other) {
    words = other.words;
    isOccupied = other.isOccupied;

    return *this;
}


long Dictionary::hash(const string &key, long tableSize) {
    long hashVal = 0;
    for (char c : key) {
        hashVal = 37 * hashVal + c;
    }

    return hashVal % tableSize;
}

void Dictionary::rehash() {
    // get temp array of items 
    long oldSize = words->getSize();
    string temp[oldSize];
    for (long i = 0, tIndex = 0; i < words->getCapacity(); i++) {
        if (isOccupied[i]) {
            temp[tIndex++] = words->get(i);
        }
    }

    // resize words
    long newCapacity = findNextPrime(words->getCapacity() * 2);
    words->resize(newCapacity);

    // resize bool
    delete[] isOccupied;
    isOccupied = new bool[newCapacity];
    for (long i = 0; i < newCapacity; i++) {
        isOccupied[i] = false;
    }

    // move temp array back into words, while also flagging bool 
    for (int i = 0; i < oldSize; i++) {
        addEntry(temp[i]);
    }
}


void Dictionary::addEntry(string entry) {
    long index = hash(entry, words->getCapacity());

    while (isOccupied[index]) {
        index++;
    }

    words->insert(entry, index);
    isOccupied[index] = true;

    if (words->getSize() * 2 > words->getCapacity()) {
        rehash();
    }
}


bool Dictionary::findEntry(string entry) {
    long index = hash(entry, words->getCapacity());

    while (isOccupied[index]) {
        if (words->get(index).compare(entry) == 0) {
            return true;
        }
    }

    return false;
}


void Dictionary::printSorted(ostream& outStream) {

}