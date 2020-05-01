// --------------------------- transactionfactory.h ----------------------------
// Enina Bogdani, Rossini Higgins, David Kang, Josiah Zacharias
// Created: 02/23/20
// Modified: 02/25/20
// -----------------------------------------------------------------------------
// Purpose: This class defines a factory that is responsible for determining
// what type of Transaction object should be instantiated based on provided
// input. Allows for dynamic binding of Transaction objects.
// ------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the formats neccessary for each type of 
//    associated Transaction object


#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "transaction.h"
#include "return.h"
#include "borrow.h"
#include "inventory.h"
#include "history.h"
#include "../movie/movie.h"
#include "../support/hashtable.h"


using namespace std;

class TransactionFactory {
    public:
        //-------------------------------------------------Public member methods
        // Will parse through passed parameter information to determine which
        // type of Transaction object to create and return
        static Transaction* createTransaction(string info, InventoryContainer&, HashTable<Customer*>&) ;
                                      
};

#endif
