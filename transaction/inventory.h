// ------------------------------- inventory.h ---------------------------------
// Enina Bogdani, Rossini Higgins, David Kang, Josiah Zacharias
// Created: 02/23/20
// Modified: 02/25/20
// -----------------------------------------------------------------------------
// Purpose: This class defines the action of displaying a Store's inventory
// -----------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"
#include "../customer/customer.h"

using namespace std;

class Inventory : public Transaction {
    // Overloaded << : prints a movie
    friend ostream& operator<<(ostream& output, const Transaction& outputTransaction);

    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates an empty Inventory object
        Inventory(InventoryContainer&);
        // Prints the Store's inventory according to the specified requirements 
        // for each different category of Movie
        virtual void doTransaction() ;

    private:
        //-------------------------------------------------Private member fields
        // All available movies in the Store
        InventoryContainer* i;
        //------------------------------------------------Private member methods

    protected:
        // Prints a string of the transaction
        virtual void print(ostream &) const;
};

#endif
