// -------------------------- transactionfactory.cpp --------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 03/16/20
// Modified: 02/25/20
// ----------------------------------------------------------------------------
// Purpose: This class implementss a factory that is responsible for
// determining what type of Transaction object should be instantiated based on
// provided input. Allows for dynamic binding of Transaction objects.
// ----------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the formats neccessary for each type of
//    associated Transaction object

#include "transactionfactory.h"
#include <string>


// ----------------------------- createTransaction ----------------------------
// Will parse through passed parameter information to determine which type of
// Transaction object to create and return a pointer of the appropriate type
// ----------------------------------------------------------------------------

Transaction* TransactionFactory::createTransaction(string info,
                                                  InventoryContainer& inventory,
                                                  HashTable<Customer*>& customers) {
    char transType = info.front();
    
    switch (transType) {
        case 'R':
            return new Return(info, inventory, customers);

        case 'B':
            return new Borrow(info, inventory, customers);

        case 'I':
            return new Inventory(inventory);

        case 'H':
            return new History(info, customers);

        default:
            cout << "ERROR: " << transType << " is not a valid transaction type. ";
            return nullptr;
    }
}
