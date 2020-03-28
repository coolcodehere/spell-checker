#include <algorithm>
#include "Dictionary.h"
#include "primes.h"

void initArray(string *arr, int capacity) {
    for (int i = 0; i < capacity; i++) {
        arr[i] = "";
    }
}

Dictionary::Dictionary() {
    capacity = 5;
    size = 0;
    arr = new string[capacity];
    initArray(arr, capacity);
}

Dictionary::Dictionary(const Dictionary& orig) {

}

Dictionary::~Dictionary() {

}

void Dictionary::copyDict(const Dictionary& orig) { 
    
}


void Dictionary::deleteDict() {

}


Dictionary& Dictionary::operator=(const Dictionary& orig) {

}


int Dictionary::hash(const string &key, int tableSize) {
    int hashVal = 0;
    for (char c : key) {
        hashVal = 37 * hashVal + c;
    }

    return hashVal % tableSize;
}


void Dictionary::addEntry(string anEntry) {
    int i = hash(anEntry, capacity);

    while(arr[i].compare("")) {
        i++;

        if (i >= capacity) {
            i = 0;
        }
    }

    arr[i] = anEntry;
    size++;

    if (size / capacity > .5) {
        resize(arr, capacity);
    }
}


bool Dictionary::findEntry(string key) {
    int i = hash(key, capacity);

    while (arr[i].compare("") != 0 && arr[i].compare(key.c_str()) != 0) {
        i++;
    }

    return arr[i].compare(key.c_str()) == 0;
}


void Dictionary::printSorted(ostream& outStream) {
    string *temp = new string[size];
    int tIdx = 0;

    for (int i = 0; i < capacity; i++) {
        if (arr[i].compare("") != 0) {
            temp[tIdx++] = arr[i];
        }
    }

    sort(temp, temp + size);

    for (int i = 0; i < size; i++) {
        cout << temp[size] << endl;
    }

    delete[] temp;
}

//SEGFAULT HERE?????
int Dictionary::resize(string *arr, int tableSize) {
    int newCap = getNextSize(tableSize);
    string temp[size];
    
    for (int i = 0, j = 0; i < capacity; i++) {
        if (this->arr[i].compare("") != 0) {
            temp[j++] = arr[i];
        }
    }

    delete[] arr;
    arr = new string[newCap];
    capacity = newCap;
    initArray(arr, capacity);
    
    
    for (int i = 0; i < size; i++) {
        addEntry("a");
    }

    // for (int i = 0; i < capacity; i++) {
    //     cout << arr[i] << endl;
    // }
}


long Dictionary::getNextSize(int capacity) {
    capacity *= 2;

    int i = 0;
    while (primes[i] < capacity) {
        i++;
    }
    
    return primes[i];
}

void Dictionary::test() {

}