// ------------------------------- customer.cpp -------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 02/23/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements a singular customer. Contains information
// about the customer as well as the movies they have checked out and their
// transaction history
// ----------------------------------------------------------------------------
// Assumptions:
//  - Input provided to the constructor will be given in the form of:
//      customerID# (int) lastName (string) firstName (string)
//  - Input data is formatted correctly

#include "customer.h"

// ------------------------------- Customer -----------------------------------
// Constructor
// Takes a string containing the customer info as parameter
// Constructs a Customer object and populates the customerID, firstName, and
// lastName fields after parsing through the passed input string
// Also initializes the customer's transaction list
// Used to create a partial object for compareTo
// ----------------------------------------------------------------------------

Customer::Customer(string info) {
    istringstream line(info);
    string ID;
    string idNumber;
    getline(line, idNumber, ' ');
    customerID = stoi(idNumber);
    getline(line, lastName, ' ');
    getline(line, firstName, ' ');
    transactionHistory = list<Transaction*>();
}


// ------------------------------ addToHistory --------------------------------
// Takes a Transaction object as parameter, and adds it to the customer's
// list of transactions
// ----------------------------------------------------------------------------

void Customer::addToHistory(Transaction* transaction) {
    transactionHistory.push_back(transaction);
}


// ------------------------------- getHistory ---------------------------------
// Takes no parameters
// Returns the customer's transaction history
// ----------------------------------------------------------------------------

list<Transaction*>* Customer::getHistory() {
    return &transactionHistory;
}


// ------------------------------ getCustomerID -------------------------------
// Takes no parameters
// Returns the customer's ID number
// ----------------------------------------------------------------------------

int Customer::getCustomerID() {
    return customerID;
}
