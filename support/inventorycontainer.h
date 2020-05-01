// ----------------------------- inventorycontainer.h -------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 03/14/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class defines an inventory container used to perform the
// actions required by the Inventory class: inserting, retrieving, and
// displaying the movies contained in an inventory.
// ----------------------------------------------------------------------------

#ifndef INVENTORYCONTAINER_H
#define INVENTORYCONTAINER_H

#include <stdio.h>
#include <iostream>
#include <sstream>
#include "bintree.h"
#include "../movie/comedy.h"
#include "../movie/drama.h"
#include "../movie/classics.h"
#include "../support/stringUtils.h"

class InventoryContainer {
    
    public:
        // Constructor: Will create an empty InventoryContainer object
        InventoryContainer();
        // Destructor: Will delete the InventoryContainer object
        ~InventoryContainer();
        // Inserts a new Movie into the inventory
        void insertMovie(Movie*);
        // Retrieves the given movie from the inventory
        Movie* retrieveMovie(string, string) const;
        // Displays all movies in the inventory
        void displayAll();
    
    private:
        // Array that holds the data
        BinTree** data;
        // Array size
        // One bucket for each possible movie genre
        static int const SIZE = 3;
};

#endif /* inventorycontainer_h */

