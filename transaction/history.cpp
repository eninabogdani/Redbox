// -------------------------------- history.cpp --------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 02/23/20
// Modified: 03/16/20
// -----------------------------------------------------------------------------
// Purpose: This class implements the action of displaying a Customer's
// transaction history.
// -----------------------------------------------------------------------------

#include "history.h"


// --------------------------------- History ----------------------------------
// Constructor
// Creates a History object and assign a Customer object to the c field
// ----------------------------------------------------------------------------

History::History(string info, HashTable<Customer*>& customers) {
    
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
    
     isValid =true;
}


// ------------------------------ doTransaction -------------------------------
// Prints the Customer's transaction history in chronological order
// ----------------------------------------------------------------------------

void History::doTransaction() {
    list<Transaction*>* customerHistory = c->getHistory();
    
    if (customerHistory->empty()) {
        cout << "No customer history" << endl;
    }
    
    for (Transaction* t : *customerHistory) {
        cout << *t;
    }
    cout << endl;
}


// -------------------------------- print -------------------------------------
// Displays a History object
// ----------------------------------------------------------------------------

void History::print(ostream& output) const {
    output
    << "Customer: " << c->getCustomerID()
    << " history: " << endl;
}
