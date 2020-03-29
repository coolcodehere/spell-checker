#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

using namespace std;

template <class T>
class ArrayList {
private:
    long capacity;
    long size;
    T *arr;
     
public:
    ArrayList();
    ArrayList(const ArrayList& other);
    ArrayList& operator=(const ArrayList& original);
    ~ArrayList() { delete[] arr; };


    // Resizes the internal array to newCapacity.
    void resize(long newCapacity);

    T get(long index) const { return arr[index]; }

    long getSize() const { return size; }

    long getCapacity() const { return capacity; }

    void insert(T value, long index) { 
        arr[index] = value; 
        size++;
    } 
};

#endif