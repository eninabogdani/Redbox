//
//  return.cpp
//  Redbox
//
//  Created by Josiah Zacharias on 3/2/20.
//  Copyright © 2020 Josiah Zacharias. All rights reserved.
//

#include "return.h"

using namespace std;

// --------------------------------- Return -----------------------------------
// Constructor
// Creates a Return object and populate the m and c fields based on passed data
// ----------------------------------------------------------------------------

Return::Return(string info, InventoryContainer& inventory, HashTable<Customer*>& customers) {
    
    istringstream line(info);
    getline(line, transactionType, ' ');

    string ID;
    int customerID;
    getline(line, ID, ' ');
    customerID = stoi(ID);
    // PUT IN OTHERS
    if (!customers.retrieve(customerID, c)) {
        cout << "ERROR: customer #" << customerID << " not found. ";
        isValid = false;
        return;
    }
    
    string format;
    getline(line, format, ' ');
    if (format != "D") {
        cout << "ERROR: format " << format << " not allowed. ";
        isValid = false;
        return;
    }
    
    string genre;
    getline(line, genre, ' ');
    string toSend;
    getline(line, toSend);
    m = inventory.retrieveMovie(genre, toSend);
    if (m == nullptr) {
        cout << "Movie not found. ";
        isValid = false;
        return;
    }
    isValid = true;
}


void Return::doTransaction() {
    // NEED TO CHECK IF MOVIE WAS BORROWED FIRST??
    m->increaseStock();
    c->addToHistory(this);
}



// ------------------------------ operator<< ----------------------------------
// Displays a Classic in the following format:
// Genre, Stock, Director, Title, Major actor, Release date
// ----------------------------------------------------------------------------

// C, Stock, Director, Title, Major actor Release date
void Return::print(ostream& output) const {
    output
    << "Customer: " << c->getCustomerID()
    << " returned \"" << m->getTitle() << "\""
    << endl;
}
