// ------------------------------- hashtable.cpp ------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 02/23/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class will implement a template for a HashTable that stores
// data in an array.
// The HashTable will use closed hashing to compute the correct array index in
// which to store the data.
// ----------------------------------------------------------------------------
// Assumptions:
//  - Only strings and ints will be accepted as Key values for this table


#include <stdio.h>


// ------------------------------- HashTable ----------------------------------
// Default constructor
// Takes no parameters
// Constructs an empty HashTable
// ----------------------------------------------------------------------------

 template <class T>
HashTable<T>::HashTable() {
     size = NULL;
     data = NULL;
 }


// ------------------------------- HashTable ----------------------------------
// Constructor
// Constructs an empty HashTable of the given size
// ----------------------------------------------------------------------------

template <class T>
HashTable<T>::HashTable(int tableSize) {
    size = tableSize;
    data = new HashEntry*[size];
    for (int i = 0; i < size; i++) {
        data[i] = nullptr;
    }
}


// ------------------------------- ~HashTable ---------------------------------
// Destructor
// Deletes the current HashTable
// ----------------------------------------------------------------------------

template <class T>
HashTable<T>::~HashTable() {
    for (int i = 0; i < size; i++) {
        if (data[i] != nullptr) {
            delete data[i]->value;
            data[i]->value = nullptr;
            delete data[i];
            data[i] = nullptr;
        }
    }
    
    delete[] data;
    data = nullptr;
}


// -------------------------------- insert ------------------------------------
// Takes a key and value as parameters, and hashes the value into the table
// based on the key
// Returns true if the insertion was succeful, false otherwise
// ----------------------------------------------------------------------------

template <class T>
bool HashTable<T>::insert(int key, T value) {
    int bucket = this->hash(key);

    for (int i = 0; i < size; i++) {
        int tryBucket = (bucket + i) % size;
        if (data[tryBucket] == nullptr) {
            data[tryBucket] = new HashEntry();
            data[tryBucket]->key = key;
            data[tryBucket]->value = value;
            return true;
        // If try to insert same key twice, return false
        } else if (data[tryBucket]->key == key) {
            return false;
        }
    }
    
    // If reach this point, table is full.
    resize();
    return insert(key, value);
}


// -------------------------------- retrieve ----------------------------------
// Takes a key and reference to a value as parameters, and returns the value
// associated with the key by setting the reference equal to it
// Returns true if the retrieval was succeful, false otherwise
// ----------------------------------------------------------------------------

template <class T>
bool HashTable<T>::retrieve(int key, T& value) const {
    int bucket = this->hash(key);

    for (int i = 0; i < size; i++) {
        int tryBucket = (bucket + i) % size;
        // nullptr means value was never inserted
        if (data[tryBucket] != nullptr && data[tryBucket]->key == key) {
            value = data[tryBucket]->value;
            return true;
        }
    }

    return false;
}


// -------------------------------- remove ------------------------------------
// Takes a key as parameter, and removes the value associated with that key
// Returns true if the removal was succeful, false otherwise
// ----------------------------------------------------------------------------

template <class T>
bool HashTable<T>::remove(int key) {
    int bucket = this->hash(key);
    for (int i = 0; i < size; i++) {
        int tryBucket = (bucket + i) % size;
        // nullptr means value was never inserted
        if (data[tryBucket] != nullptr && data[tryBucket]->key == key) {
            delete data[tryBucket];
            data[tryBucket] = nullptr;
            return true;
        }
    }
    return false;
}


// --------------------------------- hash -------------------------------------
// Takes a key as parameter, and returns the appropriate hash index
// ----------------------------------------------------------------------------

template <class T>
int HashTable<T>::hash(int key) const {
    int hashIndex = key % size;
    return hashIndex;
}


// -------------------------------- resize ------------------------------------
// Takes no parameters
// Resizes the hash table by doubling its current size
// ----------------------------------------------------------------------------

template <class T>
void HashTable<T>::resize() {
    int newSize = size * 2;
    HashEntry** newData = new HashEntry*[newSize];
    for (int i = 0; i < newSize; i++) {
        if (i < size) {
            newData[i] = data[i];
        } else {
            newData[i] = nullptr;
        }
    }
    delete[] data;
    data = newData;
    size = newSize;
}
