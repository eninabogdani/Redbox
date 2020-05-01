// ------------------------------- driver.cpp ----------------------------------
// Enina Bogdani, Rossini Higgins, David Kang, Josiah Zacharias
// Created: 02/25/20
// Modified: 02/25/20
// -----------------------------------------------------------------------------
// Purpose: This code tests the functionality of the movie store program by 
// providing movie, customer, and transaction information through input files.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input files are formatted as required by their respective object
//    classes

#include "movie/movie.h"
#include "customer/customer.h"
#include "store/store.h"
#include "support/hashtable.h"
#include "transaction/transaction.h"
#include <string>

int main() {
    Store redBox = Store("RedBox");

    ifstream data4movies("../input/data4movies.txt");
	if (!data4movies) {
		cout << "File: data4movies could not be opened." << endl;
		return 1;
	}

    ifstream data4customers("../input/data4customers.txt");
	if (!data4customers) {
		cout << "File: data4customers could not be opened." << endl;
		return 1;
	}

    ifstream data4commands("../input/data4commands.txt");
	if (!data4commands) {
		cout << "File: data4commands could not be opened." << endl;
		return 1;
	}

    redBox.populateInventory(data4movies);
    redBox.populateCustomers(data4customers);
    redBox.readTransactions(data4commands);
    redBox.executeTransactions();
    
    
    return 0;
}
