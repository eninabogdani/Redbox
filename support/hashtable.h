// ------------------------------- hashtable.h -----------------------------
// Enina Bogdani, Rossini Higgins, David Kang, Josiah Zacharias
// Created: 02/23/20
// Modified: 02/25/20
// ------------------------------------------------------------------------
// Purpose: This class will define a HashTable that stores data in an array. The
// HashTable will use open hashing to compute the correct array index in which
// to store the data.
// ------------------------------------------------------------------------
// Assumptions:
//  - Only strings and ints will be accepted as Key values for this table

#ifndef HASHTABLE_H
#define HASHTABLE_H


using namespace std;

template<class T>
class HashTable {

    public:
    
        // Default Constructor: Will create an empty HashTable object
        HashTable();
        // Constructor: Will create an empty HashTable object
        HashTable(int);
        // Destructor: Will delete the HashTable object
        ~HashTable();
        // Inserts a new object at the passed Key location
        bool insert(int, T);
        // Removes the object contained in the passed Key location
        bool remove(int);
        // Retrieves the object present at the passed Key location
        bool retrieve(int, T&) const;

    private: 
    
        struct HashEntry {
                int key;
                T value;
        };
        
        // Array that holds the data
        HashEntry** data;
        // Array size
        int size;
        // Hashing function: Takes in a Key and returns the hashed index
        int hash(int) const;
        void resize();

};

#include "hashtable.cpp"

#endif
