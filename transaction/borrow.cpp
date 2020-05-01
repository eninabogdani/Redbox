//
//  borrow.cpp
//  Redbox
//
//  Created by Josiah Zacharias on 3/2/20.
//  Copyright © 2020 Josiah Zacharias. All rights reserved.
//

#include "borrow.h"


using namespace std;


// --------------------------------- Borrow -----------------------------------
// Constructor
// Creates a Borrow object and populate the m and c fields based on passed data
// ----------------------------------------------------------------------------

Borrow::Borrow(string info, InventoryContainer& inventory, HashTable<Customer*>& customers) {
    
    istringstream line(info);
    getline(line, transactionType, ' ');

    string ID;
    int customerID;
    getline(line, ID, ' ');
    customerID = stoi(ID);
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


// ------------------------------ doTransaction -------------------------------
// Decrements the stock of a movie and loga the Borrow Transaction in
// the Customer's history field
// ----------------------------------------------------------------------------

void Borrow::doTransaction() {
    
    if (m->getStockInStore() < 1) {
        cout << "Error: all copies of " << m->getTitle() << " are currently checked out" << endl;
    } else {
        m->decreaseStock();
        c->addToHistory(this);
    }
}


// ------------------------------ operator<< ----------------------------------
// Displays a Classic in the following format:
// Genre, Stock, Director, Title, Major actor, Release date
// ----------------------------------------------------------------------------

// C, Stock, Director, Title, Major actor Release date
void Borrow::print(ostream& output) const {
    output
    << "Customer: " << c->getCustomerID()
    << " borrowed \"" << m->getTitle() << "\""
    << endl;
}
