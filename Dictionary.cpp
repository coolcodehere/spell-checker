#include <algorithm>
#include <iostream>
#include <string>
#include <tgmath.h>
#include "Dictionary.h"
#include "Primes.h"

Dictionary::Dictionary(int capacity) {
    this->capacity = capacity;
    set = new string[capacity];
    valStore = new string[capacity];
    isOccupied = new bool[capacity] {0};
}


Dictionary::~Dictionary() {
    delete[] set;
    delete[] valStore;
    delete[] isOccupied;
}


Dictionary::Dictionary(const Dictionary& other) {
    delete[] set;
    delete[] valStore;
    delete[] isOccupied;
    capacity = other.capacity;
    numVals = other.numVals;
    for (int i = 0; i < capacity; i++) {
        set[i] = other.set[i];
        valStore[i] = other.valStore[i];
        isOccupied[i] = other.isOccupied[i];
    }
}


Dictionary& Dictionary::operator=(const Dictionary& other) {
    delete[] set;
    delete[] valStore;
    delete[] isOccupied;
    capacity = other.capacity;
    numVals = other.numVals;
    set = other.set;
    valStore = other.valStore;
    isOccupied = other.isOccupied;
    return *this;
}


int Dictionary::hash(const string &val, int capacity) {
    int hashCharSum = 0;
    for (char c : val) 
        hashCharSum = hashCharSum + (int)c;
    return hashCharSum % capacity;
}


void Dictionary::rehash() {
    delete[] set;
    delete[] isOccupied;

    capacity = findNextPrime(capacity);
    set = new string[capacity];
    isOccupied = new bool[capacity] {0};
    string *tempValStore = new string[capacity];

    int tempNumVals = numVals;
    numVals = 0;

    for (int i = 0; i < tempNumVals; i++) {
        addEntry(valStore[i]);
        tempValStore[i] = valStore[i];
    }

    delete[] valStore;
    valStore = tempValStore;
}


int Dictionary::findFirstEmptyIndex(int index) {
    while (isOccupied[index]) {
        index++;

        if (index >= capacity) {
            index -= capacity;
        } 
    }

    return index;
}


void Dictionary::addEntry(string val) {
    int index = findFirstEmptyIndex(hash(val, capacity));

    valStore[numVals] = val;
    set[index] = val;
    isOccupied[index] = true;
    numVals++;

    if (numVals * 2 >= capacity) { 
        rehash();
    }
}


bool Dictionary::findEntry(string val) {
    for (int i = 0; i < numVals; i++) {
        if (valStore[i].compare(val) == 0) {
            return true;
        }
    }

    return false;
}


void Dictionary::printSorted(ostream& outStream) {
    sort(valStore, valStore + numVals);
    for (int i = 0; i < capacity; i++) {
        outStream << valStore[i] << endl;
    }
}