// -------------------------------- history.h ----------------------------------
// Enina Bogdani, Rossini Higgins, David Kang, Josiah Zacharias
// Created: 02/23/20
// Modified: 02/25/20
// -----------------------------------------------------------------------------
// Purpose: This class defines the action of displaying a Customer's transaction 
// history
// -----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"
#include "../customer/customer.h"

using namespace std;

class History : public Transaction {
    
    friend ostream& operator<<(ostream& output, const Transaction& outputTransaction);

    public:
        //-------------------------------------------------Public member methods
        // Constructor: Will create a History object and assign a Customer
        // object to the c field
        History(string, HashTable<Customer*>&);
        // Prints the Customer's transaction history in chronological order
        virtual void doTransaction() ;

    private:
        //-------------------------------------------------Private member fields
        // Pointer to the Customer object associated with this transaction
        Customer* c;
        //------------------------------------------------Private member methods

    protected:
        // Prints a string of the transaction
        virtual void print(ostream &) const;
    
};

#endif
