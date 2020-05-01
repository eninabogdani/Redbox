// ---------------------------------- store.cpp -------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 02/23/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements a singular store, which contains information
// on all available movies and all customers that are borrowing from the store.
// Will parse through input files to populate Movie, Customer, and Transaction
// objects, and then execute all transactions that are created.
// ----------------------------------------------------------------------------
// Assumptions:
//  - All input files will be provided in the following formats:
//      -Movie: genre(string) stock(int) director(string) title(string)
//        In addition, the following movie genre's input will also contain:
//         Comedy: releaseYear(int)
//         Drama: releaseYear(int)
//         Classics: majorActor(string) releaseMonth(int) releaseYear(int)
//      -Customer: customerID#(int) lastName(string) firstName(string)
//      -Transaction: actionType(char)
//        In addition, the following transaction types will also contain:
//        Borrow: customerID#(int) mediaFormat(char) movieData(Formatted above)
//        Return: customerID#(int) mediaFormat(char) movieData(Formatted above)
//        History: customerID#(int)

#include "store.h"


// -------------------------------- Store -------------------------------------
// Constructor
// Populate the storeName, inventory, and customers fields, while
// instantiating the transaction field as an empty list
// ----------------------------------------------------------------------------

Store::Store(string newName) {
    storeName = newName;
    inventory = new InventoryContainer();
    customers = new HashTable<Customer*>(maxCustomers);
    transactions = new list<Transaction*>();
}


// -------------------------------- ~Store ------------------------------------
// Destructor
// Deletes the current Store object
// ----------------------------------------------------------------------------

Store::~Store() {
    delete inventory;
    inventory = nullptr;
    delete customers;
    customers = nullptr;
    
    for (auto && t : *transactions) {
        delete t;
    }
    
    delete transactions;
    transactions =  nullptr;
}


// ---------------------------- populateInventory -----------------------------
// Fills the inventory field based on data from an input file
// ----------------------------------------------------------------------------

void Store::populateInventory(ifstream& input) {
    if (!input) {
        cout << "ERROR: movie data could not be read" << endl;
    } else {
        cout << "Populating Inventory\n------------------------------------ " << endl;
        string line;
        while (getline(input, line)) {
            MovieFactory movieHelp;
            char genre = line.front();
            Movie* newMovie = movieHelp.createMovie(genre, line);
            if (newMovie == nullptr) {
                cout << "This movie data line is not valid" << endl;
            } else {
                inventory->insertMovie(newMovie);
            }
        }
        cout << endl << endl;
    }
}


// ---------------------------- populateCustomers -----------------------------
// Fills the transactions field based on data from an input file
// ----------------------------------------------------------------------------

void Store::populateCustomers(ifstream& input) {
    if (!input) {
        cout << "ERROR: customer data could not be read" << endl;
    } else {
        string line;
        while (getline(input, line)) {
            Customer* newCustomer = new Customer(line);
            if (newCustomer->getCustomerID() == 0) {
                cout << "This customer data is not valid" << endl;
            } else {
                int customerID = newCustomer->getCustomerID();
                customers->insert(customerID, newCustomer);
            }
        }
    }
}


// ---------------------------- readTransactions ------------------------------
// Fills the transactions field based on data from an input file
// ----------------------------------------------------------------------------

void Store::readTransactions(ifstream& input) {
    if (!input) {
        cout << "ERROR: data commands could not be read" << endl;
    } else {
        cout << "Populating Transactions\n------------------------------------ " << endl;
        string line;
        while (getline(input, line)) {
            TransactionFactory transactionHelp;
            Transaction* newTransaction = transactionHelp.createTransaction(line, *inventory, *customers);
            if (newTransaction == nullptr || !newTransaction->isValid) {
                cout << "This transaction command is not valid" << endl;
                if (newTransaction != nullptr) {
                  delete newTransaction;
                  newTransaction = nullptr;
                }
            } else {
                transactions->push_back(newTransaction);
            }
        }
        cout << endl << endl;
    }
}


// --------------------------- executeTransactions ----------------------------
// Executes all transactions stored in the transactions field
// ----------------------------------------------------------------------------

void Store::executeTransactions() {
    cout << "Executing Transactions\n------------------------------------ " << endl;
    for (Transaction* t : *transactions) {
        cout << *t;
        t->doTransaction();
    }
    cout << endl << endl;
}
