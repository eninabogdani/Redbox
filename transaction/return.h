// --------------------------------- return.h ----------------------------------
// Enina Bogdani, Rossini Higgins, David Kang, Josiah Zacharias
// Created: 02/23/20
// Modified: 02/25/20
// -----------------------------------------------------------------------------
// Purpose: This class defines the action of a Customer returning a Movie to a
// Store. Will contain information related to the specific Movie being returned
// as well as the Customer that is returning the movie
// -----------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the following format:
//      customerID#(int) mediaFormat(char) movieData(formatted based on genre)

#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"
#include "../customer/customer.h"

using namespace std;

class Return : public Transaction {
    
    // Overloaded << : prints a transaction
    friend ostream& operator<<(ostream& output, const Transaction& outputTransaction);

    public:

//-------------------------------------------------Public member methods
        // Constructor: Will create a Return object and populate the m and c 
        // fields based on passed data
        Return(string, InventoryContainer&, HashTable<Customer*>&);
        // Will increment the stock of a movie and log the Return Transaction in
        // the Customer's history field
        virtual void doTransaction() ;
        

    private:
        //-------------------------------------------------Private member fields
        // Pointer to the Movie object associated with this transaction
        Movie* m;
        // Pointer to the Customer object associated with this transaction
        Customer* c;
        
    protected:
        // Prints a string of the transaction
        virtual void print(ostream &) const;
        
};

#endif
