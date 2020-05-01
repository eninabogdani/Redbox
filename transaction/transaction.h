// ------------------------------ transaction.h --------------------------------
// Enina Bogdani, Rossini Higgins, David Kang, Josiah Zacharias
// Created: 02/23/20
// Modified: 02/25/20
// -----------------------------------------------------------------------------
// Purpose: This class defines an interface for a single transaction. The object
// may be related to Movie, Store, or Customer objects depending on which type
// of Transaction object is created.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     actionType(char)
//       In addition, the following transaction types will also contain:
//         Borrow: customerID#(int) mediaFormat(char) movieData(Formatted above)
//         Return: customerID#(int) mediaFormat(char) movieData(Formatted above)
//         History: customerID#(int)

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <sstream>
#include "../movie/movie.h"
//#include "../movie/moviefactory.h"
#include "../support/hashtable.h"
#include "../support/inventorycontainer.h"
#include "../support/stringUtils.h"

using namespace std;

class Transaction {
    
    // Overloaded << : prints a movie
    friend ostream& operator<<(ostream& output, const Transaction& outputMovie);
    
    public:
        virtual ~Transaction();
    
    // Will check that the movie exists in the Store's inventory and that
        // a Customer exists with the matching ID number
        bool isValid;
    //-------------------------------------------------Public member methods
        // Using the type of Transaction object that is instantiated, determine 
        // and conduct the necessary action
        virtual void doTransaction() = 0;

    protected:
        // String representing the type of transaction
        string transactionType;
    
        // prints a string version of this Transaction
        virtual void print(ostream&) const = 0;

};

#endif
