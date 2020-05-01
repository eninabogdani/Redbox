// ------------------------------ inventory.cpp -------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 02/23/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements the action of displaying a Store's inventory.
// ----------------------------------------------------------------------------

#include "inventory.h"

// --------------------------------- Inventory --------------------------------
// Constructor
// Creates an empty Inventory object
// ----------------------------------------------------------------------------

Inventory::Inventory(InventoryContainer& inventory) {
    i = &inventory;
    isValid =true;
}


// ------------------------------ doTransaction -------------------------------
// Prints the Store's inventory according to the specified requirements for
// each different category of Movie
// ----------------------------------------------------------------------------

void Inventory::doTransaction() {
    i->displayAll();
}


// -------------------------------- print -------------------------------------
// Displays an Inventory object
// ----------------------------------------------------------------------------

void Inventory::print(ostream& output) const {
    output
    << "Store Inventory: " << endl;
}
