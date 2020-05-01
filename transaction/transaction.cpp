// ------------------------------ transaction.cpp -----------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 02/23/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class defines an interface for a single transaction. The
// object may be related to Movie, Store, or Customer objects depending on
// which type of Transaction object is created.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     actionType(char)
//       In addition, the following transaction types will also contain:
//        Borrow: customerID# mediaFormat movieData
//        Return: customerID# mediaFormat movieData
//        History: customerID#

#include "transaction.h"


// ------------------------------- operator>> ---------------------------------
// Overloaded operator>>
// Displays a Transaction object
// ----------------------------------------------------------------------------

ostream& operator<<(ostream& output, const Transaction& outputMovie) {
    outputMovie.print(output);
    return output;
}


// ------------------------------- ~Transaction -------------------------------
// Destructor
// No implementation needed
// ----------------------------------------------------------------------------

Transaction::~Transaction() {

}
